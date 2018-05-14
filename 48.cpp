#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();
        int skin = len / 2, edge = 0, level = 0;

        while (level < skin) {
            edge = len - level * 2 - 1;
            for (int j = 0; j < edge; ++j) {
                int a = level + j;
                int b = len - 1 - level;
                int c = b - j;
                int d = level;
                swap(matrix[d][a], matrix[a][b]);
                swap(matrix[d][a], matrix[b][c]);
                swap(matrix[d][a], matrix[c][d]);
            }
            ++level;
        }
    }
};

int main()
{
    Solution sol;
    const int num = 3;
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int arr3[] = {7, 8, 9};
    int arr[][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
    };
    vector<vector<int>> mat;
    for (int i = 0; i < num; ++i) {
        mat.push_back(
            vector<int>(arr[i], arr[i] + sizeof(arr[i]) / sizeof(int)));
    }

    sol.rotate(mat);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        int i = m - 1, j = 0;
        while (j < n && i >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target) {
                i--;
            } else
                j++;
        }
        return false;
    }
};

int main()
{
    // Solution sol;

    const int num = 5;
    int arr[][num] = {{1, 4, 7, 11, 15},
                      {2, 5, 8, 12, 19},
                      {3, 6, 9, 16, 22},
                      {10, 13, 14, 17, 24},
                      {18, 21, 23, 26, 30}

    };
    vector<vector<int>> mat;
    for (int i = 0; i < num; ++i) {
        mat.push_back(
            vector<int>(arr[i], arr[i] + sizeof(arr[i]) / sizeof(int)));
    }
    // for (int i = 0; i < num; ++i) {
    //    for (int j = 0; j < num; ++j) {
    //        cout << mat[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    cout << searchMatrix(mat, 26);
}

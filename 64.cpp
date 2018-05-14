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
    int minPathSum(vector<vector<int>> &grid)
    {
        int m, n;
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, INT_MAX));
        sum[0][0] = grid[0][0];
        queue<int> x_arr;
        queue<int> y_arr;
        x_arr.push(0);
        y_arr.push(0);

        while (x_arr.size()) {
            int x = x_arr.front();
            int y = y_arr.front();
            x_arr.pop();
            y_arr.pop();
            if (x + 1 < m) {
                x_arr.push(x + 1);
                y_arr.push(y);
                int tmp = sum[x][y] + grid[x + 1][y];
                sum[x + 1][y] = sum[x + 1][y] < tmp ? sum[x + 1][y] : tmp;
            }
            if (y + 1 < n) {
                // x_arr.push(x);
                // y_arr.push(y + 1);
                int tmp = sum[x][y] + grid[x][y + 1];
                sum[x][y + 1] = sum[x][y + 1] < tmp ? sum[x][y + 1] : tmp;
            }
            if (x == 0 && y + 1 < n) {
                x_arr.push(x);
                y_arr.push(y + 1);
            }
        }
        return sum[m - 1][n - 1];
    }
};

int main()
{

    const int num = 3;
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int arr3[] = {7, 8, 9};
    int arr[][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> mat;
    for (int i = 0; i < num; ++i) {
        mat.push_back(
            vector<int>(arr[i], arr[i] + sizeof(arr[i]) / sizeof(int)));
    }

    Solution sol;
    cout << sol.minPathSum(mat);
}

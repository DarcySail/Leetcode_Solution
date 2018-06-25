#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int x,
            int y)
    {
        if (memo[x][y] != 0) {
            return memo[x][y];
        }
        int left = 0, right = 0, up = 0, down = 0;
        if (x - 1 >= 0 && matrix[x][y] < matrix[x - 1][y])
            up = dfs(matrix, memo, x - 1, y);
        if (x + 1 < matrix.size() && matrix[x][y] < matrix[x + 1][y])
            down = dfs(matrix, memo, x + 1, y);
        if (y - 1 >= 0 && matrix[x][y] < matrix[x][y - 1])
            left = dfs(matrix, memo, x, y - 1);
        if (y + 1 < matrix[0].size() && matrix[x][y] < matrix[x][y + 1])
            right = dfs(matrix, memo, x, y + 1);
        memo[x][y] = max(max(up, down), max(left, right)) + 1;

        return memo[x][y];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int max_val = INT_MIN;
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return 0;
        }
        vector<vector<int>> memo(matrix.size(),
                                 vector<int>(matrix[0].size(), 0));
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (memo[i][j] == 0) {
                    int val = dfs(matrix, memo, i, j);
                    max_val = max_val > val ? max_val : val;
                }
            }
        }
        return max_val;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

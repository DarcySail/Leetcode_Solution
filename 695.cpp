#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  private:
    int dfs(vector<vector<int>> &grid, int x, int y, int row, int col)
    {
        int area = 0;
        int sum = 1;
        grid[x][y] = 0;
        if (x - 1 >= 0 && grid[x - 1][y]) {
            sum += dfs(grid, x - 1, y, row, col);
        }
        if (x + 1 < row && grid[x + 1][y]) {
            sum += dfs(grid, x + 1, y, row, col);
        }
        if (y - 1 >= 0 && grid[x][y - 1]) {
            sum += dfs(grid, x, y - 1, row, col);
        }
        if (y + 1 < col && grid[x][y + 1]) {
            sum += dfs(grid, x, y + 1, row, col);
        }
        return sum;
    }

  public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int max = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    int cur_area = dfs(grid, i, j, row, col);
                    max = max > cur_area ? max : cur_area;
                }
            }
        }

        return max;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat;
    //mat.push_back(vector<int>({0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    //mat.push_back(vector<int>({0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    //mat.push_back(vector<int>({0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}));
    //mat.push_back(vector<int>({0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}));
    //mat.push_back(vector<int>({0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}));
    //mat.push_back(vector<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}));
    mat.push_back(vector<int>({0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    mat.push_back(vector<int>({0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}));

    cout << sol.maxAreaOfIsland(mat) << endl;
}

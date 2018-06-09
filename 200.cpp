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
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        int drct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            size_t to_x = x + drct[i][0];
            size_t to_y = y + drct[i][1];
            if (to_x >= 0 && to_x < grid.size() && to_y >= 0 &&
                to_y < grid[to_x].size() && grid[to_x][to_y] == '1') {
                grid[to_x][to_y] = '0';
                dfs(grid, to_x, to_y);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int sum = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++sum;
                    dfs(grid, i, j);
                }
            }
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

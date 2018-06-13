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

int mat1[][3] = {
    {
        4, 3, 8,
    },
    {
        9, 5, 1,
    },
    {
        2, 7, 6,
    },
};

int mat2[][3] = {
    {
        2, 7, 6,
    },
    {
        9, 5, 1,
    },
    {
        4, 3, 8,
    },
};

int mat3[][3] = {
    {
        6, 7, 2,
    },
    {
        1, 5, 9,
    },
    {
        8, 3, 4,
    },
};

int mat4[][3] = {
    {
        8, 3, 4,
    },
    {
        1, 5, 9,
    },
    {
        6, 7, 2,
    },
};
class Solution
{
  public:
    bool isvalid(vector<vector<int>> &grid, int x, int y)
    {
        vector<bool> window(9, false);
        for (int i = x - 1; i < x + 2; ++i) {
            for (int j = y - 1; j < y + 2; ++j) {
                if (grid[i][j] > 9 || grid[i][j] < 1 || window[grid[i][j]]) {
                    return false;
                } else {
                    window[grid[i][j]] = true;
                }
            }
        }

        for (int i = x - 1; i < x + 2; ++i) {
            int sum = 0;
            for (int j = y - 1; j < y + 2; ++j) {
                sum += grid[i][j];
            }
            if (sum != 15) {
                return false;
            }
        }
        for (int i = x - 1; i < x + 2; ++i) {
            int sum = 0;
            for (int j = y - 1; j < y + 2; ++j) {
                sum += grid[i][j];
            }
            if (sum != 15) {
                return false;
            }
        }
        if (grid[x + 1][y - 1] + grid[x][y] + grid[x - 1][y + 1] != 15) {
            return false;
        }
        if (grid[x - 1][y - 1] + grid[x][y] + grid[x + 1][y + 1] != 15) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        if (grid.size() < 3) {
            return 0;
        }
        if (grid[0].size() < 3) {
            return 0;
        }
        int num = 0;
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[0].size() - 1; ++j) {
                if (isvalid(grid, i, j)) {
                    ++num;
                }
            }
        }
        return num;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    vector<vector<int>> mat;
    mat.push_back(vector<int>({4, 3, 8, 4}));
    mat.push_back(vector<int>({9, 5, 1, 9}));
    mat.push_back(vector<int>({2, 7, 6, 2}));
    cout << sol.numMagicSquaresInside(mat);
}

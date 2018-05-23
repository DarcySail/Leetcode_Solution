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
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i] = row[i] > grid[i][j] ? row[i] : grid[i][j];
                col[j] = col[j] > grid[i][j] ? col[j] : grid[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += min(row[i], col[j]) - grid[i][j];
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat;
    mat.push_back({3, 0, 8, 4});
    mat.push_back({2, 4, 5, 7});
    mat.push_back({9, 2, 6, 3});
    mat.push_back({0, 3, 1, 0});
    mat.push_back({8, 3, 1, 9});

    sol.maxIncreaseKeepingSkyline(mat);
}

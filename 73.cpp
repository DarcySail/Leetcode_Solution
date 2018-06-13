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

// my ugly code
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }

        for (int i = 0; i < m; ++i) {
            bool flag = false;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] != 0) {
                        matrix[i][j] = 1243123423;//magic number
                    }
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            bool flag = false;
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                for (int i = 0; i < m; ++i) {
                    if (matrix[i][j] != 0) {
                        matrix[i][j] = 1243123423;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1243123423) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

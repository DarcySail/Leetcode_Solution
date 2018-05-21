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
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = matrix.size() - 1; i >= 0; --i) {
            int val = matrix[i][0];
            for (int x = i + 1, y = 1;
                 x < matrix.size() && y < matrix[0].size(); ++y, ++x) {
                if (matrix[x][y] != val)
                    return false;
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i) {
            int val = matrix[0][i];
            for (int x = 1, y = i + 1;
                 x < matrix.size() && y < matrix[0].size(); ++y, ++x) {
                if (matrix[x][y] != val)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;

    // cout << sol.findComplement(1) << endl;
}

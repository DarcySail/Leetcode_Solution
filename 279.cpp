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
    int numSquares(int n)
    {
        int level = 1;
        vector<bool> dp(n + 1);
        vector<bool> dp_swap(n + 1);
        vector<int> sq;
        for (int i = 1, square = 1; square <= n; ++i, square = i * i) {
            dp[square] = true;
            sq.push_back(square);
        }

        for (level = 1; !dp[n]; ++level) {
            for (int m = sq.size() - 1; m >= 0; --m) {
                for (int j = n; j > 0; --j) {
                    if (dp[j] && j + sq[m] <= n) {
                        dp_swap[j + sq[m]] = true;
                    }
                }
            }
            dp = (dp_swap);
        }

        return level;
    }
};

int main()
{
    Solution sol;
    cout << sol.numSquares(6) << endl;//3
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;
}

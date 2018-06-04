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

// stupid solution
class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        if (A.size() < 3) {
            return 0;
        }
        vector<int> dp(A.size() + 1, 0);
        dp[3] = 1;
        for (int i = 4; i <= A.size(); ++i) {
            dp[i] = dp[i - 1] + i - 2;
        }

        int ans = 0, gap = A[1] - A[0], len = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == gap) {
                ++len;
            } else {
                ans += dp[len];
                gap = A[i] - A[i - 1];
                len = 2;
            }
        }
        if (len > 2) {
            ans += dp[len];
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1, 2, 3, 4});
    sol.numberOfArithmeticSlices(arr);
}

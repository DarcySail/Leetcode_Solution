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
    const int max_val = 100;

  public:
    bool canPartition(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0, half;
        vector<bool> dp(len * (max_val >> 1) + 1, false);
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }
        if (sum & 1)
            return false;
        half = sum >> 1;

        for (int i = 0; i < len; ++i) {
            if (dp[half]) {
                return true;
            }
            for (int j = half; j >= 0; --j) {
                if (dp[j] && j + nums[i] <= half) {
                    dp[j + nums[i]] = true;
                }
            }
            dp[nums[i]] = true;
        }

        return dp[half];
    }
};

int main()
{
    int con[] = {1, 5, 11, 5};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    int con2[] = {1, 2, 3, 5};
    int con3[] = {2, 2, 3, 5};
    vector<int> arr2(con2, con2 + sizeof(con2) / sizeof(int));
    vector<int> arr3(con3, con3 + sizeof(con3) / sizeof(int));
    Solution sol;

    cout << sol.canPartition(arr) << endl;
    cout << sol.canPartition(arr2) << endl;
    cout << sol.canPartition(arr3) << endl;
}

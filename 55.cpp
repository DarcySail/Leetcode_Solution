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
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 0) {
            return true;
        }
        unordered_set<int> dp;
        dp.insert(0);
        for (size_t i = 0; i < nums.size(); ++i) {
            if (dp.find(i) != dp.end()) {
                for (int j = 0; j < nums[i]; ++j) {
                    size_t to = i + j + 1;
                    if (to >= nums.size()) {
                        continue;
                    }
                    if (to == nums.size() - 1) {
                        return true;
                    }
                    dp.insert(to);
                }
            }
        }

        return dp.find(nums.size() - 1) != dp.end();
    }
};

// rubbish code
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 0) {
            return true;
        }
        vector<bool> dp(nums.size());
        dp[0] = true;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (dp[i]) {
                for (int j = 0; j < nums[i]; ++j) {
                    size_t to = i + j + 1;
                    if (to >= nums.size()) {
                        continue;
                    }
                    if (to == nums.size() - 1) {
                        return true;
                    }
                    dp[to] = true;
                }
            }
        }

        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

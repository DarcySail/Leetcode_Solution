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
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1) {
            return 0;
        }
        int max_id = -1, max_val = INT_MIN;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (max_val < nums[i]) {
                max_id = i;
                max_val = nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        return max_val >= (nums[nums.size() - 2] << 1) ? max_id : -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

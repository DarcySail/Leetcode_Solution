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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> arr;
        int count_seq = -1, i;
        for (i = 0; i < nums.size(); ++i) {
            if (count_seq == -1 || arr[count_seq] < nums[i]) {
                arr.push_back(nums[i]);
                ++count_seq;
            } else {
                auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
                *it = nums[i];
            }
        }
        return count_seq + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

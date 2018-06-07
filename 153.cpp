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
    int helper(vector<int> &nums, int start, int end)
    {
        while (start < end) {
            int mid = start + ((end - start) >> 1);
            if (nums[start] < nums[end]) {
                return nums[start];
            } else if (nums[start] <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }

    int findMin(vector<int> &nums) { return helper(nums, 0, nums.size() - 1); }
};

int main()
{
    Solution sol;
    vector<int> arr({2, 1});
    sol.findMin(arr);
}

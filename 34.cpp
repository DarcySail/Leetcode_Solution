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
    int bin_search(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = beg + ((end - beg) >> 1);
            if (nums[mid] < target) {
                beg = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int low_bound(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = beg + ((end - beg) >> 1);
            if (nums[mid] < target) {
                beg = mid + 1;
            } else if (nums[mid] >= target) {
                end = mid - 1;
            }
        }
        return beg;
    }

    int high_bound(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = beg + ((end - beg) >> 1);
            if (nums[mid] <= target) {
                beg = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            }
        }
        return beg - 1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (bin_search(nums, target) == -1) {
            return vector<int>(2, -1);
        }
        vector<int> result;
        result.push_back(low_bound(nums, target));
        result.push_back(high_bound(nums, target));
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    cout << sol.reverseBits(43261596);
}

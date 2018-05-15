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
    int findUnsortedSubarray(vector<int> &nums)
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        int min, max;
        while (left < len - 1 && nums[left] <= nums[left + 1])
            ++left;
        if (left == len - 1)
            return 0;
        while (right > 0 && nums[right] >= nums[right - 1])
            --right;
        if (left == 0 && right == len - 1) {
            return len;
        }

        min = left, max = right;
        while (left <= right) {
            cout << max << ' ' << min << endl;
            if (min == -1 && max == len) {
                return len;
            }
            while (min >= 0 && nums[min] > nums[left])
                --min;
            while (max < len && nums[max] < nums[left])
                ++max;
            ++left;
        }

        return max - min - 1;
    }
};

int main()
{
    int con[] = {1, 3, 2, 2, 2};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    cout << sol.findUnsortedSubarray(arr);
}

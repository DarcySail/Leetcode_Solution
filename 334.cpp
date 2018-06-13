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
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> arr(3, INT_MIN);
        int count_seq = -1, i, j;
        for (i = 0; i < nums.size(); ++i) {
            if (count_seq == 2) {
                return true;
            }
            if (count_seq == -1 || arr[count_seq] < nums[i]) {
                arr[++count_seq] = nums[i];
            } else {
                for (j = count_seq; j >= 0 && arr[j] >= nums[i]; --j)
                    ;
                arr[j + 1] = nums[i];
            }
        }

        return count_seq == 2;
    }
};

int main()
{
    Solution sol;
    // vector<int> arr({2, 5, 3, 4, 5});
    vector<int> arr({1, 2, 1, 2, 1, 2, 1, 2, 1, 2});

    sol.increasingTriplet(arr);
}

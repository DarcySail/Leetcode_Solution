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

//clever
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        if (nums[abs(nums[i]) - 1] > 0)
            res.push_back(abs(nums[i]));
    }
    return res;
}

//my stupid solution.
class Solution
{
  public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                int it = i;
                int last = 0;
                while (nums[it] != 0 && nums[it] != it + 1) {
                    if (last == nums[it]) {
                        result.push_back(nums[it]);
                        // cout << nums[it] << ' ';
                        nums[it] = 0;
                    }
                    last = nums[it];
                    swap(nums[nums[it] - 1], nums[it]);
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({4, 3, 2, 7, 8, 2, 3, 1});
    sol.findDuplicates(arr);
}

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
    int removeElement(vector<int> &nums, int val)
    {
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

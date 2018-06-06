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
    int minMoves(vector<int> &nums)
    {
        int min = INT_MAX, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            min = min < nums[i] ? min : nums[i];
        }

        return sum - nums.size() * min;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max = 0;
        int len = nums.size();
        int count = 0;
        for (int i = 0; i < len;) {
            count = 0;
            while (nums[i] == 1) {
                ++i;
                ++count;
            }
            max = max > count ? max : count;
            while (nums[i] == 0) {
                ++i;
            }
        }

        return max;
    }
};

int main()
{
    Solution sol;

    cout << sol.findComplement(1) << endl;
}

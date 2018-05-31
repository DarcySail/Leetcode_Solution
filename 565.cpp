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
    int arrayNesting(vector<int> &nums)
    {
        int max_len = 0, len, it, last;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                for (it = i, len = -1, last = -1; it >= 0;
                     ++len, last = it, it = nums[it], nums[last] = -1)
                    ;
                nums[i] = -len;
                max_len = max_len > -nums[i] ? max_len : -nums[i];
            }
        }
        return max_len;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({5, 4, 0, 3, 1, 6, 2});
    cout << sol.arrayNesting(arr) << endl;
}

#include <algorithm>
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
    int findTargetSumWays(vector<int> &nums, int S)
    {
        vector<map<int, int>> entry_dict(nums.size() + 1, map<int, int>());
        entry_dict[0][0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            map<int, int>::iterator it = entry_dict[i].begin();
            for (; it != entry_dict[i].end(); ++it) {
                int val = it->first;
                entry_dict[i + 1][val + nums[i]] += it->second;
                entry_dict[i + 1][val - nums[i]] += it->second;
            }
        }
        return entry_dict[nums.size()][S];
    }
};

int main()
{
    Solution sol;
    int con[] = {1, 1, 1, 1, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    cout << sol.findTargetSumWays(arr, 3);
}
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
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> dict;
        int max_len = 0;
        for (auto i : nums) {
            ++dict[i];
        }
        for (auto i : dict) {
            if (dict.find(i.first - 1) != dict.end()) {
                max_len = max_len > dict[i.first] + dict[i.first - 1]
                              ? max_len
                              : dict[i.first] + dict[i.first - 1];
            }
        }

        return max_len;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1, 3, 2, 2, 5, 2, 3, 7});
    cout << sol.findLHS(arr);
}

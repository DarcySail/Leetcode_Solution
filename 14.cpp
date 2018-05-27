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
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0) {
            return "";
        }

        string pre = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int longest = pre.length();
            for (int j = 0; j < longest; ++j) {
                if (pre[j] != strs[i][j]) {
                    pre = pre.substr(0, j);
                    break;
                }
            }
        }
        return pre;
    }
};

int main()
{
    Solution sol;
    vector<string> arr({"flower", "flow", "flight"});
    vector<string> arr1({"dog", "dracecar", "dcar"});
    cout << sol.longestCommonPrefix(arr);
    cout << sol.longestCommonPrefix(arr1);
}

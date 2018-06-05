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
    bool checkInclusion(string s1, string s2)
    {
        vector<int> dict(256, 0);
        int win_size = s1.size();
        for (auto i : s1) {
            ++dict[i];
        }

        vector<int> tmp_win(dict);
        for (size_t left = 0, right = 0;
             left < s2.length() && right < s2.length(); ++right) {
            if (dict[s2[right]]-- > 0)
                --win_size;

            while (win_size == 0) {
                if (s1.size() == right - left + 1) {
                    return true;
                }
                if (dict[s2[left++]]++ >= 0) {
                    ++win_size;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.checkInclusion("ky", "wkckfykxlribaypk") << endl;
    cout << sol.checkInclusion("ky", "ainwkckifykxlribaypk") << endl;
    cout << sol.checkInclusion("ab", "eidbaooo") << endl;
    cout << sol.checkInclusion("ab", "eidboaoo") << endl;
}

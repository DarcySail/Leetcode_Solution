#include <algorithm>
#include <climits>
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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        if (s.length() == 0)
            return result;

        vector<int> dict(256, 0);
        int win_size = p.length();
        for (auto i : p)
            ++dict[i];
        for (size_t i = 0; i < p.length(); ++i) {
            if (dict[s[i]]-- > 0) {
                --win_size;
            }
        }

        if (win_size == 0) {
            result.push_back(0);
        }
        for (size_t left = 0, right = p.length(); right < s.length();
             ++left, ++right) {
            if (++dict[s[left]] > 0) {
                ++win_size;
            }
            if (dict[s[right]]-- > 0) {
                --win_size;
            }
            if (win_size == 0) {
                result.push_back(left + 1);
            }
        }
        return result;
    }
};

void pv(vector<int> &arr)
{
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}
int main()
{
    Solution sol;
    vector<int> arr = sol.findAnagrams("abab", "ab");
    pv(arr);
    arr = sol.findAnagrams("cbaebabacd", "abc");
    pv(arr);
}

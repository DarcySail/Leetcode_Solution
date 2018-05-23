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
    bool isIsomorphic(string s, string t)
    {
        int lens = s.length();
        int lent = t.length();
        if (lens != lent)
            return false;
        map<char, char> dict;
        map<char, char> dict_t;
        for (int i = 0; i < lens; ++i) {
            if (dict.find(s[i]) == dict.end()) {
                dict[s[i]] = t[i];
            } else if (dict[s[i]] != t[i]) {
                return false;
            }
        }
        for (int i = 0; i < lens; ++i) {
            if (dict_t.find(t[i]) == dict_t.end()) {
                dict_t[t[i]] = s[i];
            } else if (dict_t[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isIsomorphic("foo", "bar") << endl;
    cout << sol.isIsomorphic("foo", "baa") << endl;
}

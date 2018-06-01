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
    bool isSubsequence(string s, string t)
    {
        int i, j;
        for (i = 0, j = 0; i < t.length() && j < s.length(); ++i) {
            if (s[j] == t[i]) {
                ++j;
            }
        }
        return s.length() == j;
    }
};

int main()
{
    Solution sol;
    sol.isSubsequence("abc", "ahbgdc");
}
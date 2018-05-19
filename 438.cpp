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
        int dict[128] = {0};
        int lens = s.length(), lenp = p.length();
        vector<int> dp(s.length(), 0);

        return NULL;
    }
};

int main()
{
    Solution sol;
    sol.findAnagrams("abab", "ab");
}

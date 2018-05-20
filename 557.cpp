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
    string reverseWords(string s)
    {
        int len = s.length();
        int start = 0, end = 0;
        for (int i = 0; i < len;) {
            for (; i < len && s[i] != ' '; ++i)
                ;
            end = i;
            if (start == end) {
                ++i;
                continue;
            }
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            ++i;
        }
        return s;
    }
};

int main()
{
    Solution sol;

    cout << sol.reverseWords(" Let's take LeetCode contest ") << endl;
}

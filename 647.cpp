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
    int countSubstrings(string s)
    {
        int total = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (check_palindromic(s, i, j)) {
                    ++total;
                }
            }
        }

        return total;
    }
    static bool check_palindromic(string &s, int start, int end)
    {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string a = "abc";
    string b = "aaa";
    cout << sol.countSubstrings(a) << endl;
    cout << sol.countSubstrings(b) << endl;
}
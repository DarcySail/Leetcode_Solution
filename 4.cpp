#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
            return s;
        vector<int> dp(s.length(), 1);
        int max_len = 0;
        int max_len_idx = 0;
        for (int i = 1; i < s.length(); ++i) {
            int len1 = 1, len2 = 1;
            //cout << "idx1: " << i - dp[i - 1] << ' ';
            //cout << "idx2: " << i - 1 - dp[i - 1] << ' ';
            if (i - dp[i - 1] >= 0 && s[i] == s[i - dp[i - 1]])
                len1 = dp[i - 1] + 1;
            if (i - dp[i - 1] - 1 >= 0 && s[i] == s[i - dp[i - 1] - 1])
                len2 = dp[i - 1] + 2;

            dp[i] = len1 > len2 ? len1 : len2;
            cout << dp[i] << ' ';
            if (max_len < dp[i]) {
                max_len = dp[i];
                max_len_idx = i;
            }
        }

        return s.substr(max_len_idx - max_len + 1, max_len);
    }
};

int main()
{
    Solution sol;
    string a = "suhangaaa";
    string b = "babad";
    string c = "cbbd";
    string d = "abcba";
    string e = "abcca";
    string f = "abcccba";
    string g = "babadada";
    cout << sol.longestPalindrome(a) << endl;
    cout << sol.longestPalindrome(b) << endl;
    cout << sol.longestPalindrome(c) << endl;
    cout << sol.longestPalindrome(d) << endl;
    cout << sol.longestPalindrome(e) << endl;
    cout << sol.longestPalindrome(f) << endl;
    cout << sol.longestPalindrome(g) << endl;
}
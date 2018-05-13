#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        int result = 1;
        vector<int> arr(s.length(), 1);
        for (int i = 1; i < arr.size(); ++i) {
            int cur_val = 1;
            for (int j = i - 1; j >= i - arr[i - 1]; --j) {
                if (s[i] != s[j]) {
                    ++cur_val;
                } else {
                    break;
                }
            }
            result = result > cur_val ? result : cur_val;
            arr[i] = cur_val;
        }
        return result;
    }
};

int main()
{
    string a = "abcabcbb";
    string b = "bbbb";
    string c = "pwwkew";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(a) << endl;
    cout << sol.lengthOfLongestSubstring(b) << endl;
    cout << sol.lengthOfLongestSubstring(c) << endl;
}
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
    string decodeString(string s)
    {
        int len = s.length();
        int start, end;
        int times = 0;
        int close_brackets = 0;
        string result;
        for (int i = 0; i < len;) {
            if (isdigit(s[i])) {
                start = i;
                while (isdigit(s[i]))
                    ++i;
                end = i;
                times = stoi(s.substr(start, end - start));

                // find sub string
                string sub_string;
                start = ++i;
                close_brackets = 1;
                while (close_brackets) {
                    if (s[i] == '[')
                        ++close_brackets;
                    if (s[i] == ']')
                        --close_brackets;
                    ++i;
                }
                end = i - 1;
                sub_string = s.substr(start, end - start);
                sub_string = decodeString(sub_string);
                for (int j = 0; j < times; ++j) {
                    result += sub_string;
                }
            } else {
                start = i;
                while (isalpha(s[i]))
                    ++i;
                end = i;
                result += s.substr(start, end - start);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string a = "3[a]2[bc]";
    string b = "3[a2[c]]";
    string c = "2[abc]3[cd]ef";
    cout<<sol.decodeString(a)<<endl;
    cout<<sol.decodeString(b)<<endl;
    cout<<sol.decodeString(c)<<endl;
}
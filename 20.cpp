#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        int len = s.length();
        stack<char> p_stack;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                p_stack.push(s[i]);
                continue;
            }

            if (p_stack.size() == 0) {
                return false;
            }
            if (s[i] == ')') {
                if ('(' != p_stack.top()) {
                    return false;
                }
            } else if (s[i] == '}') {
                if ('{' != p_stack.top()) {
                    return false;
                }
            } else if (s[i] == ']') {
                if ('[' != p_stack.top()) {
                    return false;
                }
            }
            p_stack.pop();
        }
        if (p_stack.size()) {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isValid("{}") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("(]") << endl;
    cout << sol.isValid("((") << endl;
    cout << sol.isValid("]") << endl;
}

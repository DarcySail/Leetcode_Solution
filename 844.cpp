#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> ss, st;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '#') {
                if (!ss.empty())
                    ss.pop();
            } else {
                ss.push(S[i]);
            }
        }

        for (int i = 0; i < T.length(); ++i) {
            if (T[i] == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(T[i]);
            }
        }

        if (ss.size() != st.size()) {
            return false;
        }

        while (ss.size()) {
            if (ss.top() != st.top()) {
                return false;
            }
            ss.pop();
            st.pop();
        }

        return true;
    }
};

int main()
{
    Solution sol;
    sol.backspaceCompare("y#f#o##f", "y#fo##f");
}

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
    bool rotateString(string A, string B)
    {
        if (A.length() != B.length()) {
            return false;
        }
        string two = A + A;
        return two.find(B) != string::npos;
    }
};

int main()
{
    Solution sol;
    cout << sol.rotateString("abcde", "cdeab") << endl;
    cout << sol.rotateString("abcde", "abced") << endl;
}

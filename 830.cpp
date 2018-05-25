#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// ugly code
class Solution
{
  public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> result;
        if (S.length() == 0) {
            return result;
        }
        S += S[S.length() - 1] + 1;
        int len = S.length();
        int start = 0;
        for (int i = 1; i < len; ++i) {
            if (S[i - 1] != S[i]) {
                if (i - start >= 3) {
                    result.push_back(vector<int>({start, i - 1}));
                }
                start = i;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    sol.largeGroupPositions("abbxxxxzzy");
    sol.largeGroupPositions("abc");
    sol.largeGroupPositions("aaa");
    sol.largeGroupPositions("a");
    sol.largeGroupPositions("abcdddeeeeaabbbcd");
}

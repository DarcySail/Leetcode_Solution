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
    void helper(vector<string> &result, string str, unsigned int start)
    {
        for (; start < str.length() && !isalpha(str[start]); ++start) {
        }
        if (start < str.length()) {
            helper(result, str, start + 1);
            if (str[start] >= 'a' && str[start] <= 'z') {
                str[start] = toupper(str[start]);
            } else {
                str[start] = tolower(str[start]);
            }
            result.push_back(str);
            helper(result, str, start + 1);
        }

        return;
    }
    vector<string> letterCasePermutation(string S)
    {
        vector<string> result;
        result.push_back(S);
        helper(result, S, 0);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
}

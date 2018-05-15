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
    map<char, string> dict;
    vector<string> _letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.length() == 1) {
            for (int i = 0; i < dict[digits[0]].length(); ++i) {
                char c = dict[digits[0]][i];
                result.push_back(string(1, c));
            }
            return result;
        }

        vector<string> sub_result;
        sub_result = _letterCombinations(digits.substr(1, digits.length() - 1));
        for (int i = 0; i < dict[digits[0]].length(); ++i) {
            char c = dict[digits[0]][i];
            for (int j = 0; j < sub_result.size(); ++j) {
                result.push_back(string(1, c) + sub_result[j]);
            }
        }

        return result;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return vector<string>();
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";

        return _letterCombinations(digits);
    }
};

int main()
{
    Solution sol;
    vector<string> arr = sol.letterCombinations("234");
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << endl;
    }
}

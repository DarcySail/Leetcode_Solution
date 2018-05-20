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
    vector<string> findWords(vector<string> &words)
    {
        string str_arr[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        map<char, int> dict;
        for (size_t j = 0; j < 3; ++j) {
            for (size_t i = 0; i < str_arr[j].length(); ++i) {
                dict[str_arr[j][i]] = j;
                dict[str_arr[j][i] + 'A' - 'a'] = j;
            }
        }
        vector<string> result;
        for (size_t i = 0; i < words.size(); ++i) {
            int flag = dict[words[i][0]];
            for (size_t j = 1; j < words[i].length(); ++j) {
                if (flag != dict[words[i][j]]) {
                    flag = -1;
                    break;
                }
            }
            if (-1 != flag) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string con[] = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> arr;
    for (int i = 0; i < 3; ++i)
        arr.push_back(con[i]);

    sol.findWords(arr);
}

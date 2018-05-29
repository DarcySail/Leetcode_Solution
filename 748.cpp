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
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        string result;
        vector<int> dict(26, 0);
        int window_size = 0;
        for (auto i : licensePlate)
            if (isalpha(i)) {
                ++dict[tolower(i) - 'a'];
                ++window_size;
            }

        int min_len = INT_MAX;
        for (auto i : words) {
            vector<int> tmp(dict);
            int tmp_size = window_size;
            for (auto j : i) {
                if (tmp[j - 'a'] > 0) {
                    --tmp[j - 'a'];
                    --tmp_size;
                }
            }
            if (tmp_size == 0 && i.length() < min_len) {
                result = i;
                min_len = i.length();
            }
            if (min_len == window_size) {
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> arr({"step", "steps", "stripe", "stepple"});
    vector<string> arr1({"looks", "pest", "stew", "show"});
    cout << sol.shortestCompletingWord("1s3 456", arr1) << endl;
    cout << sol.shortestCompletingWord("1s3 PSt", arr) << endl;
}

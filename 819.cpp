#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, bool> ban_word;
        unordered_map<string, int> dict;
        for (int i = 0; i < banned.size(); ++i) {
            ban_word[banned[i]] = true;
        }

        int max_num = 0;
        string max_str;
        int len = paragraph.length();
        for (int i = 0; i < len; ++i) {
            int start = i;
            for (; i < len && isalpha(paragraph[i]); ++i) {
                paragraph[i] = tolower(paragraph[i]);
            }
            if (start == i) {
                continue;
            }
            string word = paragraph.substr(start, i - start);
            if (ban_word.find(word) == ban_word.end()) {
                ++dict[word];
            }
            if (dict[word] > max_num) {
                max_num = dict[word];
                max_str = word;
            }
        }

        return max_str;
    }
};

int main()
{
    Solution sol;
    vector<string> arr({"hit"});
    cout << sol.mostCommonWord(
        "....   Bob hit a ball, the hit BALL flew far after it was hit.", arr);
}

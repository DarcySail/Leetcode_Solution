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
    string frequencySort(string s)
    {
        int arr[256] = {0};
        string result;
        for (auto i : s)
            ++arr[i];
        map<int, vector<char>> dict;
        for (int i = 0; i < 256; ++i) {
            if (arr[i]) {
                dict[arr[i]].push_back(i);
            }
        }
        for (auto it = dict.rbegin(); it != dict.rend(); ++it) {
            for (int i = 0; i < it->second.size(); ++i) {
                result += string(it->first, it->second[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.frequencySort("tree") << endl;
}

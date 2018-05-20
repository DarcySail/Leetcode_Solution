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
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> apear;
        int len = S.length();
        vector<int> result(len, 0);
        for (int i = 0; i < len; ++i) {
            if (S[i] == C) {
                apear.push_back(i);
            }
        }

        int idx = 0;
        for (; idx <= apear[0]; ++idx) {
            result[idx] = apear[0] - idx;
        }
        for (size_t i = 0; i < apear.size() - 1; ++i) {
            for (; idx <= apear[i + 1]; ++idx) {
                result[idx] = min(idx - apear[i], apear[i + 1] - idx);
            }
        }
        for (; idx < len; ++idx) {
            result[idx] = idx - apear[apear.size() - 1];
        }
        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = sol.shortestToChar("loveleetcode", 'e');
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

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
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int row = 0, col = 0;
        int len = S.length();
        vector<int> result(2, 0);
        if (len == 0) {
            return result;
        }

        int remain = 100;
        for (int i = 0; i < len; ++i) {
            int val = widths[S[i] - 'a'];
            if (remain >= val) {
                col += val;
                remain -= val;
            } else {
                ++row;
                col = val;
                remain = 100 - val;
            }
        }

        result[0] = row + 1;
        result[1] = col;

        return result;
    }
};

int main() { Solution sol; }

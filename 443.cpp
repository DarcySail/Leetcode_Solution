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
    int compress(vector<char> &chars)
    {
        int len = chars.size();
        string result;
        for (int i = 0; i < len;) {
            char val = chars[i];
            int start = i++;
            while (i < len && chars[i] == val)
                ++i;
            result += val;
            if (i - start != 1) {
                result += to_string(i - start);
            }
        }
        for (int i = 0; i < result.length(); ++i) {
            chars[i] = result[i];
        }

        return result.length();
    }
};

int main()
{
    Solution sol;
    vector<char> arr({'a', 'a', 'b', 'b', 'c', 'c', 'c'});

    cout << sol.compress(arr);
}

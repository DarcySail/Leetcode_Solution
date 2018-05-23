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
    int numJewelsInStones(string J, string S)
    {
        int ans = 0;
        int dict[256] = {0};
        int j_len = J.length();
        int s_len = S.length();
        for (int i = 0; i < j_len; ++i) {
            dict[J[i]] = 1;
        }
        for (int i = 0; i < s_len; ++i) {
            if (dict[S[i]])
                ++ans;
        }
        return ans;
    }
};

int main()
{
    int con[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    //for (int i = 0; i < 28; ++i)
    //    cout << i << ' ' << sol.isPowerOfThree(i) << endl;
}

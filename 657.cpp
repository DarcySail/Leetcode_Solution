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
    bool judgeCircle(string moves)
    {
        int len = moves.length();
        int x = 0, y = 0;
        for (int i = 0; i < len; ++i) {
            if (moves[i] == 'U') {
                ++y;
            } else if (moves[i] == 'D') {
                --y;
            } else if (moves[i] == 'L') {
                --x;
            } else if (moves[i] == 'R') {
                ++x;
            }
        }

        return 0 == x && 0 == y;
    }
};

int main()
{
    int con[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    for (int i = 0; i < 28; ++i)
        cout << i << ' ' << sol.isPowerOfThree(i) << endl;
}

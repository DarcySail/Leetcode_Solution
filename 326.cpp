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
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        int max = 1162261467;
        return !(max % n);
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

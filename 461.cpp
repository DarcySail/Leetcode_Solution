#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        unsigned int v = x ^ y;
        unsigned int c;
        for (c = 0; v; c++) {
            v &= v - 1;
        }
        return c;
    }
};

int main()
{
    Solution sol;
    int x = 1, y = 4;
    cout << sol.hammingDistance(x, y);
}
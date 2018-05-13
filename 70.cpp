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
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int one = 1;
        int two = 2;
        int now = 3;
        for (int i = 2; i < n; ++i) {
            now = one + two;
            one = two;
            two = now;
        }

        return now;
    }
};

int main()
{
    Solution sol;
}
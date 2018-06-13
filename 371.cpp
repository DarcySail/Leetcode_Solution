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
    int getSum(int a, int b)
    {
        int c, d;
        while (a & b) {
            c = a ^ b;
            d = (a & b) << 1;
            a = c;
            b = d;
        }
        return a | b;
    }
};

int main()
{
    Solution sol;
    cout << sol.getSum(1, 2) << endl;
    cout << sol.getSum(100, 2) << endl;
    cout << sol.getSum(9, 2) << endl;
    cout << sol.getSum(16, 2) << endl;
    cout << sol.getSum(0, 2) << endl;
    cout << sol.getSum(20, 30) << endl;
}

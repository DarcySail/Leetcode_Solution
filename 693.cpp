#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool hasAlternatingBits(int n)
    {
        int low_bit = !(n & 1);
        while (n) {
            if (!(n & 1 ^ low_bit)) {
                return false;
            }
            low_bit = n & 1;
            n >>= 1;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    cout << sol.hasAlternatingBits(0) << endl;
    cout << sol.hasAlternatingBits(5) << endl;
    cout << sol.hasAlternatingBits(7) << endl;
    cout << sol.hasAlternatingBits(11) << endl;
    cout << sol.hasAlternatingBits(10) << endl;
}

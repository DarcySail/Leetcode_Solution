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
    int findComplement(int num)
    {
        unsigned int result = 0;
        unsigned int mask = 0;
        unsigned int val = num;
        while (val) {
            val >>= 1;
            mask = (mask << 1) | 1;
        }
        val = num;
        return ~val & mask;
    }
};

int main()
{
    Solution sol;

    cout << sol.findComplement(5) << endl;
    cout << sol.findComplement(1) << endl;
}

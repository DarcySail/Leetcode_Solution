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
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t high = 1 << 31;
        uint32_t low = 1;
        for (int i = 0; i < 16; ++i) {
            uint32_t high_val = n & (high >> i);
            uint32_t low_val = n & (low << i);
            if ((high_val != 0) ^ (low_val != 0)) {
                if (high_val) {
                    n = n & (~high_val);
                    n = n | (low << i);
                } else {
                    n = n & (~low_val);
                    n = n | (high >> i);
                }
            }
        }
        return n;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    cout << sol.reverseBits(43261596);
}

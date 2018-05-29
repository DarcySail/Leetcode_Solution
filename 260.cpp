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
    vector<int> singleNumber(vector<int> &nums)
    {
        int xor_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xor_sum ^= nums[i];
        }

        int mask = 0x1;
        while (!(mask & xor_sum)) {
            mask <<= 1;
        }

        int xor_0 = 0, xor_1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & mask) {
                xor_1 ^= nums[i];
            } else {
                xor_0 ^= nums[i];
            }
        }
        return {xor_0, xor_1};
    }
};

int main() { Solution sol; }

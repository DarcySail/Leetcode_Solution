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
    int findLengthOfLCIS(vector<int> &nums)
    {
        int max = 0, len = 0, last = INT_MIN;
        for (int i = 0; i < nums.size(); last = nums[i], ++i) {
            len = nums[i] > last ? len + 1 : 1;
            max = max > len ? max : len;
        }
        return max;
    }
};

int main() { Solution sol; }

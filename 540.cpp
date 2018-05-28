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
    int singleNonDuplicate(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return result;
    }
};

int main() { Solution sol; }

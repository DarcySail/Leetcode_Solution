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
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> dict;
        int most_freq = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (dict.find(nums[i]) != dict.end()) {
                ++dict[nums[i]][0];
                most_freq =
                    most_freq > dict[nums[i]][0] ? most_freq : dict[nums[i]][0];
                dict[nums[i]][2] = i;
            } else {
                dict[nums[i]] = vector<int>(3, i);
                dict[nums[i]][0] = 1;
            }
        }

        int ans = INT_MAX;
        for (auto i : dict) {
            if (i.second[0] == most_freq) {
                ans = ans < i.second[2] - i.second[1] + 1
                          ? ans
                          : i.second[2] - i.second[1] + 1;
            }
        }

        return ans;
    }
};

int main() { Solution sol; }

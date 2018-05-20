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
    int arrayPairSum(vector<int> &nums)
    {
        int len = nums.size();
        // sort
        vector<int> count_sort(20005, 0);
        for (int i = 0; i < len; ++i) {
            ++count_sort[nums[i] + 10000];
        }
        for (int i = 0, idx = 0; i < 20005;) {
            if (count_sort[i]) {
                nums[idx++] = i - 10000;
                --count_sort[i];
            } else {
                ++i;
            }
        }

        long long sum = 0;
        for (int i = 0; i < len; i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};

int main() { Solution sol; }
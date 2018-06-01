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

// 大二写的
int max(int *a, int n)
{
    int max = a[0], sum = max;
    for (int i = 1; i < n; i++) {
        sum = sum < 0 ? a[i] : sum + a[i];
        max = sum > max ? sum : max;
    }
    return max;
}
// 现在写的
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max = max > sum ? max : sum;
            sum = sum > 0 ? sum : 0;
        }
        return max;
    }
};

int main() { Solution sol; }

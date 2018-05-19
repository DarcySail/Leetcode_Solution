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
    int missingNumber(vector<int> &nums)
    {
        int len = nums.size();
        unsigned long long sum = 0;
        unsigned long long cal_sum = 0;
        cal_sum = len * (len + 1) / 2;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }

        return cal_sum - sum;
    }
};

int main()
{
    int con[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    cout << sol.missingNumber(arr);
}
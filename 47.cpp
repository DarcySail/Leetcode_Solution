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

void pv(vector<int> arr)
{
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}

class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        while (true) {
            result.push_back(nums);
            int n = nums.size();
            int j = n - 2;
            for (; j >= 0 && nums[j + 1] <= nums[j]; --j) {
            }
            if (j == -1) {
                return result;
            }
            int m = n - 1;
            for (; m > j && nums[m] <= nums[j]; --m) {
            }
            swap(nums[j], nums[m]);
            reverse(nums.begin() + j + 1, nums.end());
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1, 2, 1});
    sol.permuteUnique(arr);
}

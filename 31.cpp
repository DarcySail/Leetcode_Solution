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
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int j = n - 2;
        for (; j >= 0 && nums[j + 1] <= nums[j]; --j) {
        }
        if (j == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int m = n - 1;
        for (; m > j && nums[m] <= nums[j]; --m) {
        }
        swap(nums[j], nums[m]);
        reverse(nums.begin() + j + 1, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1, 5, 1});
    sol.nextPermutation(arr);
    for (auto i : arr)
        cout << i << ' ';
//    sol.nextPermutation(arr);
//    for (auto i : arr)
//        cout << i << ' ';
}

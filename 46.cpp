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
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1) {
            return vector<vector<int>>(1, nums);
        }

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> sub(nums);
            sub.erase(sub.begin() + i);
            vector<vector<int>> tmp = permute(sub);
            for (int j = 0; j < tmp.size(); ++j) {
                tmp[j].insert(tmp[j].begin(), nums[i]);
            }
            result.insert(result.end(), tmp.begin(), tmp.end());
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1, 2, 34});
    auto mat = sol.permute(arr);
    for (auto i : mat) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

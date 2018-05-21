#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int row = nums.size(), col = nums[0].size();
        if (r * c != nums.size() * nums[0].size()) {
            return nums;
        }

        vector<vector<int>> result(r, vector<int>(c, 0));
        int size = row * col;
        for (int i = 0; i < size; ++i) {
            result[i / c][i - i / c * c] = nums[i / col][i - i / col * col];
        }
        return result;
    }
};

int main()
{
    Solution sol;

    cout << sol.findComplement(5) << endl;
    cout << sol.findComplement(1) << endl;
}

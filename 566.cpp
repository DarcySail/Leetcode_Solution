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
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        if (findNums.size() == 0 || nums.size() == 0) {
            return vector<int>();
        }
        int len = nums.size();
        unordered_map<int, int> dict;
        vector<int> greater(len, -1);
        greater[len - 1] = -1;
        dict[nums[len - 1]] = len - 1;

        for (int i = len - 2; i >= 0; --i) {
            dict[nums[i]] = i;
            for (int it = i + 1; it < len;) {
                if (nums[i] < nums[it]) {
                    greater[i] = it;
                    break;
                } else if (greater[it] != -1) {
                    it = greater[it];
                } else if (greater[it] == -1) {
                    greater[it] = -1;
                    break;
                }
            }
        }

        vector<int> result(findNums.size(), 0);
        for (int i = 0; i < findNums.size(); ++i) {
            int val = greater[dict[findNums[i]]];
            result[i] = val == -1 ? -1 : nums[val];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> a({4, 1, 2});
    vector<int> b({1, 3, 4, 2});

    sol.nextGreaterElement(a, b);
}

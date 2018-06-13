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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *helper(vector<int> &nums, int beg, int end)
    {
        if (beg > end) {
            return NULL;
        }
        int mid = beg + ((end - beg) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, beg, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

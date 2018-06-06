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

// other's brilliant sol
// class Solution
//{
//  public:
//    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
//    {
//        vector<TreeNode *> stk;
//        for (int i = 0; i < nums.size(); ++i) {
//            TreeNode *cur = new TreeNode(nums[i]);
//            while (!stk.empty() && stk.back()->val < nums[i]) {
//                cur->left = stk.back();
//                stk.pop_back();
//            }
//            if (!stk.empty())
//                stk.back()->right = cur;
//            stk.push_back(cur);
//        }
//        return stk.front();
//    }
//};

class Solution
{
  public:
    TreeNode *helper(vector<int> &nums, int start, int end)
    {
        if (end <= start) {
            return NULL;
        }
        int max_id = start, max_val = INT_MIN;
        for (int i = start; i < end; ++i) {
            if (max_val < nums[i]) {
                max_val = nums[i];
                max_id = i;
            }
        }
        TreeNode *root = new TreeNode(max_val);
        root->left = helper(nums, start, max_id);
        root->right = helper(nums, max_id + 1, end);

        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return helper(nums, 0, nums.size());
    }
};

int main()
{
    Solution sol;
    vector<int> arr({3, 2, 1, 6, 0, 5});
    sol.constructMaximumBinaryTree(arr);
}

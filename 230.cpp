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
    int k_val, cur_idx;
    void helper(TreeNode *root, int k)
    {
        if (!root) {
            return;
        }
        helper(root->left, k);
        ++cur_idx;
        if (cur_idx == k) {
            k_val = root->val;
        }
        helper(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        cur_idx = 0;
        helper(root, k);
        return k_val;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

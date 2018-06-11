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
    bool dfs(TreeNode *root, int target, int sum)
    {
        if (!root->left && !root->right) { // is leaf
            return sum + root->val == target;
        }
        if (root->left && dfs(root->left, target, sum + root->val)) {
            return true;
        }
        if (root->right && dfs(root->right, target, sum + root->val)) {
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        return dfs(root, sum, 0);
    }
};

int main()
{
    Solution sol;
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    a.left = &b;
    a.right = &c;
    sol.hasPathSum(&a, 9);
}

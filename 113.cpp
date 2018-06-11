#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
    void dfs(TreeNode *root, int target, vector<vector<int>> &result,
             vector<int> &stk, int sum)
    {
        stk.push_back(root->val);
        if (!root->left && !root->right &&
            sum + root->val == target) { // is leaf
            result.push_back(stk);
            stk.pop_back();
            return;
        }
        if (root->left) {
            dfs(root->left, target, result, stk, sum + root->val);
        }
        if (root->right) {
            dfs(root->right, target, result, stk, sum + root->val);
        }
        stk.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return vector<vector<int>>();
        vector<int> stk;
        vector<vector<int>> result;
        dfs(root, sum, result, stk, 0);
        return result;
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

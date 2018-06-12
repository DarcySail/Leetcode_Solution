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

// 仔细阅读他的代码，发现他改变了顺序。
// 我的代码严格按照题给顺序书写。
// other's brilliant sol
TreeNode *prev = NULL;

void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

// my ugly code
class Solution
{
  public:
    void helper(TreeNode *node, queue<TreeNode *> &q)
    {
        if (node == NULL) {
            return;
        }
        q.push(node);
        helper(node->left, q);
        helper(node->right, q);
    }

    void flatten(TreeNode *root)
    {
        queue<TreeNode *> q;
        helper(root, q);
        TreeNode head(0);
        TreeNode *last = &head, *it;
        while (q.size() != 0) {
            it = q.front();
            q.pop();
            last->right = it;
            last->left = NULL;
            last = it;
        }
    }
};

int main()
{
    Solution sol;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);

    a.left = &b;
    a.right = &e;
    b.left = &c;
    b.right = &d;
    e.right = &f;

    sol.flatten(&a);
}
//    1
//   / \
//  2   5
// / \   \
//3   4   6

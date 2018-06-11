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
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder,
                     unordered_map<int, int> &dict, int p_start, int p_end,
                     int i_start, int i_end)
    {
        if (p_start > p_end || i_start > i_end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[p_start]);
        int val = preorder[p_start];
        root->left =
            helper(preorder, inorder, dict, p_start + 1,
                   p_start + dict[val] - i_start, i_start, dict[val] - 1);
        root->right =
            helper(preorder, inorder, dict, p_start + dict[val] - i_start + 1,
                   p_end, dict[val] + 1, i_end);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> dict(inorder.size());
        for (size_t i = 0; i < inorder.size(); ++i) {
            dict[inorder[i]] = i;
        }
        return helper(preorder, inorder, dict, 0, preorder.size() - 1, 0,
                      preorder.size() - 1);
    }
};

void print_tree(TreeNode *root)
{
    if (!root) {
        return;
    }
    print_tree(root->left);
    cout << root->val << ' ';
    print_tree(root->right);
}
int main()
{
    Solution sol;
    // vector<int> pre({3, 9, 20, 15, 7});
    // vector<int> ino({9, 3, 15, 20, 7});
    vector<int> pre({1, 2, 3});
    // vector<int> ino({2, 3, 1});
    vector<int> ino({3, 2, 1});
    TreeNode *root = sol.buildTree(pre, ino);
    print_tree(root);
}

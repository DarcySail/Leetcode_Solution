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
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder,
                     unordered_map<int, int> &dict, int i_start, int i_end,
                     int p_start, int p_end)
    {
        if (p_start > p_end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[p_end]);
        int val = postorder[p_end];
        root->left = helper(inorder, postorder, dict, i_start, dict[val] - 1,
                            p_start, p_start + dict[val] - i_start - 1);
        root->right = helper(inorder, postorder, dict, dict[val] + 1, i_end,
                             p_start + dict[val] - i_start, p_end - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> dict(inorder.size());
        for (size_t i = 0; i < inorder.size(); ++i) {
            dict[inorder[i]] = i;
        }
        return helper(inorder, postorder, dict, 0, postorder.size() - 1, 0,
                      postorder.size() - 1);
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

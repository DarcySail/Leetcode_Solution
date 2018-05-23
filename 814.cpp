#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
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
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL) {
            return NULL;
        }

        //可以写的更简洁一点，不过速度提升不大，省掉一次函数调用的开销
        //所以不写了。而且这个代码更清晰一些。
        TreeNode *left, *right;
        left = root->left == NULL ? NULL : pruneTree(root->left);
        right = root->right == NULL ? NULL : pruneTree(root->right);

        root->left = left;
        root->right = right;

        if (!left && !right && root->val == 0) {
            return NULL;
        }
        return root;
    }
};

int main() { Solution sol; }

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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root == NULL) {
            return NULL;
        }
        if (root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        } else if (root->val < L) {
            root->left = NULL;
            return trimBST(root->right, L, R);
        } else {
            root->right = NULL;
            return trimBST(root->left, L, R);
        }
    }
};

int main()
{
    Solution sol;

    cout << sol.trimBST(NULL, 0, 1) << endl;
}

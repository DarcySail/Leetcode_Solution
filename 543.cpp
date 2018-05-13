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
    int depth(TreeNode *root, int *max_diameter)
    {
        if (!root) {
            return 0;
        }
        int left = 0, right = 0;
        if (root->left)
            left = depth(root->left, max_diameter) + 1;
        if (root->right)
            right = depth(root->right, max_diameter) + 1;
        int distance = left + right;
        *max_diameter = *max_diameter > distance ? *max_diameter : distance;
        return left > right ? left : right;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        int max_diameter = 0;
        int left = 0, right = 0;
        if (root->left)
            left = depth(root->left, &max_diameter) + 1;
        if (root->right)
            right = depth(root->right, &max_diameter) + 1;
        int distance = left + right;
        max_diameter = max_diameter > distance ? max_diameter : distance;

        return max_diameter;
    }
};

int main()
{
    Solution sol;
    TreeNode *root;
    cout << sol.diameterOfBinaryTree(root);
}
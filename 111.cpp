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

// my ugly code
class Solution
{
  public:
    int helper(TreeNode *root, int cur_dep)
    {
        if (!root->left && !root->right) {
            return cur_dep;
        }
        int left = root->left ? helper(root->left, cur_dep + 1) : INT_MAX;
        int right = root->right ? helper(root->right, cur_dep + 1) : INT_MAX;
        return left < right ? left : right;
    }

    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        return helper(root, 1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

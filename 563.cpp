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
  private:
    unsigned int tilt_sum = 0;

    unsigned int helper(TreeNode *root)
    {
        if (root == NULL) {
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);
        unsigned int tilt = left > right ? left - right : right - left;
        tilt_sum += tilt;

        return left + right + root->val;
    }

  public:
    int findTilt(TreeNode *root)
    {
        helper(root);
        return tilt_sum;
    }
};

int main()
{
    Solution sol;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(-2);

    a.left = &b;
    a.right = &c;
    cout<<sol.findTilt(&a);
}

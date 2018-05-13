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
    int sum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root) {
            return NULL;
        }
        convertBST(root->right);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        convertBST(root->left);
        return root;
    }
};

int main()
{
    Solution sol;
    cout << sol.countSubstrings(b) << endl;
}
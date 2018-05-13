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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        Solution sol;
        TreeNode *root;
        cout << sol.diameterOfBinaryTree(root);
    }
};

int main()
{
    Solution sol;
    TreeNode *root;
    cout << sol.diameterOfBinaryTree(root);
}
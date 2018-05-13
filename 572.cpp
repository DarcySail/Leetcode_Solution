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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s || !t) {
            return !t;
        }
        TreeNode *cur;

        return false;
    }

    TreeNode *find_node(TreeNode *s, TreeNode *t)
    {
        TreeNode *cur = s;
        int val = t->val;
        while (1) {
            if (val < cur->val) {
                if (!cur->left) {
                }
            } else if (val > cur->val) {
            } else {
                return cur;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    TreeNode a, b;

    sol.isSubtree(&a, b &);
}
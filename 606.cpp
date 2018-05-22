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
    string tree2str(TreeNode *t)
    {
        if (!t) {
            return "";
        }
        string left, right;
        left = tree2str(t->left);
        right = tree2str(t->right);

        left = (left.length() == 0) && (right.length() == 0) ? left
                                                             : "(" + left + ")";
        right = right.length() == 0 ? right : "(" + right + ")";
        string result;
        result = to_string(t->val);
        result += left + right;
        return result;
    }
};

int main() { Solution sol; }

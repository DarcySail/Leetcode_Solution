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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        int level_num = 0;
        vector<TreeNode *> queue;

        queue.push_back(root);
        while (true) {
            vector<TreeNode *> level_queue;
            result.push_back(vector<int>());
            while (queue.size()) {
                if (queue[0]->left) {
                    level_queue.push_back(queue[0]->left);
                }
                if (queue[0]->right) {
                    level_queue.push_back(queue[0]->right);
                }
                result[level_num].push_back(queue[0]->val);
                queue.erase(queue.begin());
            }
            if (level_queue.size() == 0) {
                break;
            }
            queue = level_queue;
            ++level_num;
        }
        for (size_t i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }

        return result;
    }
};

int main()
{
    Solution sol;
    TreeNode root(3);
    TreeNode a(9);
    TreeNode b(30);
    TreeNode c(15);
    TreeNode d(7);

    root.left = &a;
    root.right = &b;
    b.left = &c;
    b.right = &d;

    vector<vector<int>> result;
    result = sol.levelOrder(&root);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        vector<vector<int>> result;
        if (!root) {
            return;
        }
        int level_num = 0;
        vector<TreeLinkNode *> queue;

        queue.push_back(root);
        while (true) {
            vector<TreeLinkNode *> level_queue;
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
            TreeLinkNode *last = NULL;
            for (int i = level_queue.size() - 1; i >= 0; --i) {
                level_queue[i]->next = last;
                last = level_queue[i];
            }
            queue = level_queue;
            ++level_num;
        }

        return;
    }
};

int main()
{
    Solution sol;
    TreeLinkNode root(3);
    TreeLinkNode a(9);
    TreeLinkNode b(30);
    TreeLinkNode c(15);
    TreeLinkNode d(7);

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

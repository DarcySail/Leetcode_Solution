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

class Solution
{
  public:
    int findBottomLeftValue(TreeNode *root)
    {
        vector<vector<int>> result;
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

        return result[result.size() - 1][0];
    }
};

int main() { Solution sol; }

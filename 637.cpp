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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root) {
            return vector<double>();
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

        vector<double> ans;
        for (int i = 0; i < result.size(); ++i) {
            double sum = 0;
            for (int j = 0; j < result[i].size(); ++j) {
                sum += result[i][j];
            }
            ans.push_back(sum / result[i].size());
        }
        return ans;
    }
};

int main() { Solution sol; }

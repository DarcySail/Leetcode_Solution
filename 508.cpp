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

class Solution
{
  public:
    map<int, int> dict;
    int helper(TreeNode *root, int &most)
    {
        if (!root) {
            return 0;
        }
        int left = 0, right = 0;
        if (root->left) {
            left = helper(root->left, most);
        }
        if (root->right) {
            right = helper(root->right, most);
        }
        int sum = left + right + root->val;
        ++dict[sum];
        most = most > dict[sum] ? most : dict[sum];
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> result;
        int most_freq = 0;
        helper(root, most_freq);

        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (it->second == most_freq) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};

int main() { Solution sol; }

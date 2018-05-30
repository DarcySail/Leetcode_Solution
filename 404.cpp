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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        int left = 0, right = 0, sum = 0;
        left = sumOfLeftLeaves(root->left);
        right = sumOfLeftLeaves(root->right);
        if (root->left && !root->left->left && !root->left->right) {
            left += root->left->val;
        }
        sum = left + right;
        return sum;
    }
};

int main() { Solution sol; }

// 审错题，下面的代码是求所有左节点的和
// 题目要求左右左叶子的和
// class Solution
//{
//  public:
//    int sumOfLeftLeaves(TreeNode *root)
//    {
//        if (!root) {
//            return 0;
//        }
//        int left = 0, right = 0, sum = 0;
//        left = sumOfLeftLeaves(root->left);
//        right = sumOfLeftLeaves(root->right);
//        left += root->left ? root->left->val : 0;
//        sum = left + right;
//        return sum;
//    }
//};

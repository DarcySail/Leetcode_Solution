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

        if (is_same(s, t)) {
            return true;
        }
        if (isSubtree(s->left, t)) {
            return true;
        }
        if (isSubtree(s->right, t)) {
            return true;
        }

        return false;
    }

    bool is_same(TreeNode *s, TreeNode *t)
    {
        if (!s || !t) {
            return !s && !t;
        }

        if (s->val != t->val) {
            return false;
        }

        bool left, right;
        left = is_same(s->left, t->left);
        right = is_same(s->right, t->right);
        return left && right;
    }
};

int main()
{
    Solution sol;
    TreeNode a(3);
    TreeNode b(4);
    TreeNode c(5);
    TreeNode d(1);
    TreeNode e(2);
    TreeNode f(0);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    e.left = &f;

    TreeNode a2(4);
    TreeNode b2(1);
    TreeNode c2(2);
    a2.left = &b2;
    a2.right = &c2;

    cout << sol.isSubtree(&a, &a2);
}

// Subtree of Another binary search Tree
// class Solution
//{
//  public:
//    bool isSubtree(TreeNode *s, TreeNode *t)
//    {
//        if (!s || !t) {
//            return !t;
//        }
//        TreeNode *cur;
//        cur = find_node(s, t);
//        if (!cur) {
//            return false;
//        }
//
//        return is_same(cur, t);
//    }
//
//    bool is_same(TreeNode *s, TreeNode *t)
//    {
//        if (!s || !t) {
//            return !s && !t;
//        }
//
//        if (s->val != t->val) {
//            return false;
//        }
//
//        bool left, right;
//        left = is_same(s->left, t->left);
//        right = is_same(s->right, t->right);
//        return left && right;
//    }
//
//    TreeNode *find_node(TreeNode *s, TreeNode *t)
//    {
//        TreeNode *cur = s;
//        int val = t->val;
//        while (cur) {
//            if (val < cur->val) {
//                cur = cur->left;
//            } else if (val > cur->val) {
//                cur = cur->right;
//            } else {
//                return cur;
//            }
//        }
//
//        return NULL;
//    }
//};
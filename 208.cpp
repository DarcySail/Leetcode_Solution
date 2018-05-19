#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
	char node[26];
}

class Trie {
public:
	char *root;
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
    Solution sol;

sol.isSubtree(&a, &a2);
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
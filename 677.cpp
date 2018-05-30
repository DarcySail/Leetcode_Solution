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
//#define CHAR_SIZE 256
using namespace std;

class MapSum
{
  public:
    struct TrieNode {
        TrieNode(int _val = 0) : val(_val)
        {
            val = _val;
            con = vector<TrieNode *>(256, NULL);
        }
        vector<TrieNode *> con;
        int val;
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    MapSum() { root = new TrieNode(); }

    void insert(string key, int val)
    {
        TrieNode *it = root;
        for (int i = 0; i < key.length(); ++i) {
            if (!it->con[key[i]]) {
                it->con[key[i]] = new TrieNode();
            }
            it = it->con[key[i]];
        }
        it->val = val;
    }

    int helper(TrieNode *node)
    {
        if (!node) {
            return 0;
        }
        int sum = node->val;
        for (int i = 0; i < 256; ++i) {
            if (node->con[i]) {
                sum += helper(node->con[i]);
            }
        }
        return sum;
    }

    int sum(string prefix)
    {
        TrieNode *it = root;
        int sum = 0;
        for (int i = 0; i < prefix.length(); ++i) {
            if (!it) {
                return 0;
            }
            it = it->con[prefix[i]];
        }
        sum += helper(it);
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main()
{

    MapSum obj;
    obj.insert("aa", 3);
    string prefix = "a";
    int param_2 = obj.sum(prefix);
    cout << param_2 << endl;
    obj.insert("aa", 2);
    param_2 = obj.sum(prefix);
    cout << param_2 << endl;
    prefix = "aa";
    param_2 = obj.sum(prefix);
    cout << param_2 << endl;
    obj.insert("aaa", 3);
    prefix = "aaa";
    param_2 = obj.sum(prefix);
    cout << param_2 << endl;
    prefix = "bbb";
    param_2 = obj.sum(prefix);
    cout << param_2 << endl;
}

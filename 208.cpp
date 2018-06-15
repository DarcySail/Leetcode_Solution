#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Trie
{
  public:
    struct TrieNode {
        TrieNode(bool _is_leaf)
        {
            is_leaf = _is_leaf;
            con = vector<TrieNode *>(26, NULL);
        }
        vector<TrieNode *> con;
        bool is_leaf;
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(false); }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *it = root;
        for (size_t i = 0; i < word.length(); ++i) {
            if (!it->con[word[i] - 'a']) {
                it->con[word[i] - 'a'] = new TrieNode(false);
            }
            it = it->con[word[i] - 'a'];
        }
        it->is_leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *it = root;
        for (size_t i = 0; i < word.length(); ++i) {
            it = it->con[word[i] - 'a'];
            if (!it) {
                return false;
            }
        }
        return it->is_leaf;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *it = root;
        for (size_t i = 0; i < prefix.length(); ++i) {
            it = it->con[prefix[i] - 'a'];
            if (!it) {
                return false;
            }
        }
        return true;
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
    Trie *obj = new Trie();
    //obj->insert("suhang");
    cout << obj->search("s") << endl;
    cout << obj->startsWith("su") << endl;
    cout << obj->startsWith("au") << endl;
}
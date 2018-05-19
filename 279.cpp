#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

void flatten(TreeNode *root)
{
    while (root) {
        if (root->left && root->right) {
            TreeNode *t = root->left;
            while (t->right)
                t = t->right;
            t->right = root->right;
        }

        if (root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}

class Solution
{
  public:
    int numSquares(int n)
    {
        int level = 1;
        vector<bool> dp(n + 1);
        vector<bool> dp_swap(n + 1);
        vector<int> sq;
        for (int i = 1, square = 1; square <= n; ++i, square = i * i) {
            dp[square] = true;
            sq.push_back(square);
        }

        for (level = 1; !dp[n]; ++level) {
            for (int m = sq.size() - 1; m >= 0; --m) {
                for (int j = n; j > 0; --j) {
                    if (dp[j] && j + sq[m] <= n) {
                        dp_swap[j + sq[m]] = true;
                    }
                }
            }
            dp = (dp_swap);
        }

        return level;
    }
};

int main()
{
    Solution sol;
    cout << sol.numSquares(6) << endl; // 3
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;
}

class LRUCache
{
  public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }

    void set(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
            touch(it);
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }

  private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;

    void touch(HIPII::iterator it)
    {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }

    HIPII cache;
    LI used;
    int _capacity;
};

class Solution
{
  public:
    int trap(int A[], int n)
    {
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while (left <= right) {
            if (A[left] <= A[right]) {
                if (A[left] >= maxleft)
                    maxleft = A[left];
                else
                    res += maxleft - A[left];
                left++;
            } else {
                if (A[right] >= maxright)
                    maxright = A[right];
                else
                    res += maxright - A[right];
                right--;
            }
        }
        return res;
    }
};

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool detectCapitalUse(string word)
    {
        int len = word.length();
        if (len == 1) {
            return true;
        }

        bool head = true;
        bool tail = true;
        head = word[0] >= 'A' && word[0] <= 'Z' ? true : false;
        tail = word[1] >= 'A' && word[1] <= 'Z' ? true : false;
        if (!head && tail) {
            return false;
        }
        int i;
        for (i = 1; i < len && word[i] <= 'Z'; ++i)
            ;
        if (i == len) {
            return true;
        }
        if (i != 1) {
            return false;
        }
        for (; i < len && word[i] >= 'a'; ++i)
            ;
        if (i != len) {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    cout << sol.detectCapitalUse("USA") << endl;
}

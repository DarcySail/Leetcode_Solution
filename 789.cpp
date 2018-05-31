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
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int d = abs(target[0]) + abs(target[1]);
        for (auto g : ghosts)
            if (d >= abs(target[0] - g[0]) + abs(target[1] - g[1]))
                return false;
        return true;
    }
};

int main() { Solution sol; }

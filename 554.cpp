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
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> dict;
        int max_cnt = 0;
        for (int i = 0; i < wall.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                ++dict[sum];
                max_cnt = max_cnt > dict[sum] ? max_cnt : dict[sum];
            }
        }

        return wall.size() - max_cnt;
    }
};

int main() { Solution sol; }

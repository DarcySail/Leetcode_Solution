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
    int dfs(vector<vector<int>> &mat, vector<bool> &visited, int x)
    {
        if (visited[x]) {
            return 0;
        }

        visited[x] = true;
        for (int i = 0; i < mat.size(); ++i) {
            if (mat[x][i] == 1) {
                dfs(mat, visited, i);
            }
        }
        return 1;
    }

    int findCircleNum(vector<vector<int>> &M)
    {
        int f_c = 0;
        vector<bool> visited(M.size(), false);
        for (int i = 0; i < M.size(); ++i) {
            f_c += dfs(M, visited, i);
        }

        return f_c;
    }
};

int main() { Solution sol; }

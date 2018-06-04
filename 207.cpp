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
    bool dfs(int start, vector<vector<int>> &graph, vector<bool> &marked,
             vector<bool> &visited)
    {
        if (visited[start]) {
            return false;
        }

        marked[start] = true;
        visited[start] = true;
        for (int i = 0; i < graph[start].size(); ++i) {
            if (!dfs(graph[start][i], graph, marked, visited)) {
                return false;
            }
        }
        visited[start] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<bool> marked(numCourses, false);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto i : prerequisites) {
            graph[i.first].push_back(i.second);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!marked[i]) {
                vector<bool> visited(numCourses, false);
                if (!dfs(i, graph, marked, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(pair<int, int>(0, 1));
    prerequisites.push_back(pair<int, int>(0, 2));
    prerequisites.push_back(pair<int, int>(1, 2));
    cout << sol.canFinish(3, prerequisites);
}

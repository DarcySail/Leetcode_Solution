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

// other's brilliant sol
class Solution
{
  public:
    std::vector<std::vector<int>>
    allPathsSourceTarget(std::vector<std::vector<int>> &graph)
    {

        std::vector<std::vector<int>> result;
        std::vector<int> current;

        helper(result, graph, current, 0);

        return result;
    }

    void helper(std::vector<std::vector<int>> &result,
                const std::vector<std::vector<int>> &graph,
                std::vector<int> &current, int pos)
    {

        current.push_back(pos);

        if (graph[pos].size() == 0) {

            if (pos == graph.size() - 1) {
                result.push_back(current);
            }
        }

        for (int k = 0; k < graph[pos].size(); ++k) {
            helper(result, graph, current, graph[pos][k]);
        }
        current.pop_back();
    }
};
// my stupid solution
class Solution
{
  public:
    vector<vector<int>> dfs(vector<vector<int>> &graph, vector<bool> &visited,
                            int start)
    {
        if (visited[start]) {
            return vector<vector<int>>();
        }

        visited[start] = true;
        vector<vector<int>> result;
        for (size_t i = 0; i < graph[start].size(); ++i) {
            vector<vector<int>> sub_path;
            if (!visited[graph[start][i]]) {
                sub_path = dfs(graph, visited, graph[start][i]);
            }
            for (auto it : sub_path) {
                result.push_back(it);
            }
        }
        // for (auto it : result) {
        for (size_t i = 0; i < result.size(); ++i) {
            result[i].insert(result[i].begin(), start);
        }
        if (result.size() == 0) {
            result.push_back(vector<int>(1, start));
        }
        visited[start] = false;

        return result;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        vector<bool> visited(graph.size(), false);
        result = dfs(graph, visited, 0);
        for (int i = result.size() - 1; i >= 0; --i) {
            if (result[i][result[i].size() - 1] != graph.size() - 1) {
                result.erase(result.begin() + i);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> a({1, 2});
    vector<int> b({3});
    vector<int> c({3});
    vector<int> d({});
    vector<vector<int>> mat;
    mat.push_back(a);
    mat.push_back(b);
    mat.push_back(c);
    mat.push_back(d);
    sol.allPathsSourceTarget(mat);
}

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
    unordered_map<int, int> cal_in_degree(int numCourses,
                                          vector<vector<int>> &graph)
    {
        unordered_map<int, int> in_degree(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            in_degree[i] = 0;
        }
        for (auto i : graph) {
            for (auto j : i) {
                ++in_degree[j];
            }
        }
        return in_degree;
    }

    int has_0_degree_node(unordered_map<int, int> &in_degree)
    {
        for (auto i : in_degree) {
            if (i.second == 0) {
                return i.first;
            }
        }
        return -1;
    }

    //这段代码没考虑自环的情况
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> result;
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto i : prerequisites) {
            graph[i.second].push_back(i.first);
        }
        unordered_map<int, int> in_degree = cal_in_degree(numCourses, graph);

        int idx = has_0_degree_node(in_degree);
        for (; - 1 != idx; idx = has_0_degree_node(in_degree)) {
            result.push_back(idx);
            in_degree.erase(idx);
            for (auto i : graph[idx]) {
                --in_degree[i];
            }
        }

        if (in_degree.size() != 0) {
            return vector<int>();
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<pair<int, int>> arr;
    arr.push_back(pair<int, int>(1, 0));
    sol.findOrder(2, arr);
}

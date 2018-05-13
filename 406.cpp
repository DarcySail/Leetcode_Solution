#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        int i = 0;
        sort(people.begin(), people.end(), cmp);

        vector<pair<int, int>> sol;
        for (i = 0; i < people.size(); ++i) {
            sol.insert(sol.begin() + people[i].second, people[i]);
        }
        return sol;
    }

    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

int main()
{
    Solution sol;
    vector<pair<int, int>> arr;
    arr.push_back(pair<int, int>(7, 0));
    arr.push_back(pair<int, int>(4, 4));
    arr.push_back(pair<int, int>(7, 1));
    arr.push_back(pair<int, int>(5, 0));
    arr.push_back(pair<int, int>(6, 1));
    arr.push_back(pair<int, int>(5, 2));
    arr = sol.reconstructQueue(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
}
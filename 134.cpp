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

// other's clear sol
class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start(0), total(0), tank(0);
        // if car fails at 'start', record the next station
        for (int i = 0; i < gas.size(); i++)
            if ((tank = tank + gas[i] - cost[i]) < 0) {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        return (total + tank < 0) ? -1 : start;
    }
};

// my solution
class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> tmp_con(gas);
        vector<int> tmp_con2(cost);
        gas.insert(gas.end(), tmp_con.begin(), tmp_con.end());
        cost.insert(cost.end(), tmp_con2.begin(), tmp_con2.end());
        size_t start = 0;
        int remain = 0;
        size_t len = tmp_con.size();
        for (size_t i = 0; i < gas.size(); ++i) {
            int cur_remain = remain + gas[i] - cost[i];
            if (cur_remain >= 0) {
                remain = cur_remain;
            } else {
                remain = gas[i] - cost[i] > 0 ? gas[i] - cost[i] : 0;
                start = i + 1;
            }
            if (i - start == len) {
                return start;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    cout << sol.reverseBits(43261596);
}

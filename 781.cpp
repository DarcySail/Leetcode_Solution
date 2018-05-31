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

// my sol
class Solution
{
  public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> dict;
        int sum = 0;
        for (auto i : answers) {
            if (dict.find(i) == dict.end()) {
                dict[i] = i;
            } else if (dict[i] == 0) {
                dict[i] = i;
                sum += i + 1;
            } else {
                --dict[i];
            }
        }
        for (auto i : dict) {
            sum += i.first + 1;
        }
        return sum;
    }
};
// other's sol
int numRabbits(vector<int>& answers) {
        map<int, int> c;
        for (int i : answers) c[i]++;
        int res = 0;
        for (auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
int main()
{
    Solution sol;
    vector<int> arr1({1, 1, 2});
    vector<int> arr2({10, 10, 10});
    vector<int> arr3({});
    vector<int> arr4({2, 2, 2, 2});
    vector<int> arr5({0, 0, 0, 0});
    cout << sol.numRabbits(arr1) << endl;
    cout << sol.numRabbits(arr2) << endl;
    cout << sol.numRabbits(arr3) << endl;
    cout << sol.numRabbits(arr4) << endl;
    cout << sol.numRabbits(arr5) << endl;
}

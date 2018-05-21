#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int distributeCandies(vector<int> &candies)
    {
        int len = candies.size();
        unordered_map<int, int> dict;
        dict.reserve(10005);
        for (int i = 0; i < candies.size(); ++i) {
            ++dict[candies[i]];
        }
        int ret = dict.size() * 2 > len ? len >> 1 : dict.size();

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<int> arr({1, 1, 2, 2, 3, 3});
    vector<int> arr2({1,1,2,3});
    cout << sol.distributeCandies(arr) << endl;
    cout << sol.distributeCandies(arr2) << endl;
}

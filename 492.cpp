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
    vector<int> constructRectangle(int area)
    {
        for (int mid = sqrt(area); mid > 0; mid--)
            if (!(area % mid))
                return {area / mid, mid};
    }
};

// ugly code
class Solution
{
  public:
    vector<int> constructRectangle(int area)
    {
        unordered_set<int> set;
        pair<int, int> min_pair;
        int min = INT_MAX;
        for (int i = area; i > 0; --i) {
            if (area % i == 0) {
                if (set.find(i) != set.end()) {
                    break;
                }
                int quotient = area / i;
                set.insert(i);
                set.insert(quotient);
                if (min > quotient - i) {
                    min_pair = make_pair(i, quotient);
                }
            }
        }
        return vector<int>({min_pair.first, min_pair.second});
    }
};

int main()
{
    Solution sol;
    sol.constructRectangle(0);
    sol.constructRectangle(1);
    sol.constructRectangle(2);
    sol.constructRectangle(4);
    sol.constructRectangle(17);
    sol.constructRectangle(16);
    sol.constructRectangle(1000);
}

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
    int maxProfit(vector<int> &prices)
    {
        int max_sum = 0;
        int lowest = INT_MAX;
        int local_max_sum = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (lowest < prices[i]) {
                local_max_sum = prices[i] - lowest;
                max_sum = max_sum > local_max_sum ? max_sum : local_max_sum;
            } else {
                lowest = prices[i];
                local_max_sum = 0;
            }
        }

        return max_sum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({7, 1, 5, 3, 6, 4});
    cout << sol.maxProfit(arr);
}

// old solution
// int maxProfit(vector<int>& prices)
//{
//    if(prices.size() == 0)  return 0;
//    int max = 0;
//
//    int min_value = prices[0];
//    for(int i = 1; i < prices.size(); ++i)
//        if(min_value > prices[i])
//            min_value = prices[i];
//        else
//            max = max > prices[i] - min_value ? max : prices[i] - min_value;
//    return max;
//}
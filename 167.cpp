#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

//问：为什么当两个指针所指数字之和小于时，选择将左侧数字往右挪动，而不是选择将右侧数字向右挪动呢？仅仅将左侧数字向右挪动，是否能保证该策略一定有解呢？
//答：回到问题最初的状态，我们将两个指针所指数字记为ai和aj，目标值记为y。当ai+aj≤y时，存在两种做法：将i加一或者将j加一，但是由于j已经是最大的下标了，只有可能将i加一。同时这样的操作之后，可以保证移动之后的情形下依旧有解，即问题划归为相同的子问题，可以通过相同的方式求解。
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        int l = 0, r = sz - 1;
        int res = numbers[l] + numbers[r] - target;
        while (res != 0) {
            if (res < 0) {
                ++l;
            }
            else {
                --r;
            }
            res = numbers[l] + numbers[r] - target;
        }
        return vector<int>{l+1, r+1};
    }
};

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> dict;
        vector<int> result(2, 0);

        for (int i = 0; i < numbers.size(); ++i) {
            int complement = target - numbers[i];
            if (dict.find(complement) != dict.end()) {
                result[0] = dict[complement];
                result[1] = i + 1;
                break;
            }
            dict[numbers[i]] = i + 1;
        }
        return result;
    }
};

int main() { Solution sol; }

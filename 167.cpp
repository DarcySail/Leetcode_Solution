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

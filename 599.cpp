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
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> dict;
        vector<string> result;
        if (list1.size() < list2.size()) {
            list1.swap(list2);
        }

        for (int i = 0; i < list1.size(); ++i) {
            dict[list1[i]] = i;
        }

        int min_sum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (dict.find(list2[i]) != dict.end()) {
                min_sum =
                    min_sum < i + dict[list2[i]] ? min_sum : i + dict[list2[i]];
            }
        }

        for (int i = 0; i < list2.size(); ++i) {
            if (dict.find(list2[i]) != dict.end() &&
                dict[list2[i]] + i == min_sum) {
                result.push_back(list2[i]);
            }
        }

        return result;
    }
};

int main() { Solution sol; }

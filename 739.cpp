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

void print_vector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; --i) {
            if (temperatures[i] < temperatures[i + 1]) {
                result[i] = 1;
            } else {
                int idx = i + 1 + result[i + 1];
                while (temperatures[i] >= temperatures[idx] &&
                       result[idx] != 0) {
                    idx += result[idx];
                }
                result[i] = temperatures[i] < temperatures[idx] ? idx - i : 0;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({73, 74, 75, 71, 69, 72, 76, 73});
    sol.dailyTemperatures(arr);
}

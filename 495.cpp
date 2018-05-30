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
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int len = timeSeries.size();
        int last = 0;
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += last > timeSeries[i] ? timeSeries[i] + duration - last
                                        : duration;
            last = timeSeries[i] + duration;
        }

        return sum;
    }
};

int main() { Solution sol; }

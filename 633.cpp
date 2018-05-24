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
    bool judgeSquareSum(int c)
    {
        map<long, long> dict;
        for (long i = 0; i * i <= c; ++i) {
            long squra = i * i;
            dict[squra] = true;
            if (dict.find(c - squra) != dict.end()) {
                return true;
            }
        }

        return false;
    }
};

int main() { Solution sol; }

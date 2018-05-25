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
    bool isOneBitCharacter(vector<int> &bits)
    {
        int arr[2][2] = {{0, 1}, {0, 0}};
        int len = bits.size();
        int pos = 0;
        for (int i = 0; i < len - 1; ++i) {
            pos = arr[pos][bits[i]];
        }
        return pos == 0;
    }
};

int main() { Solution sol; }

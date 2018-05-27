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
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }

        string str(to_string(x));
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }
};

int main() { Solution sol; }

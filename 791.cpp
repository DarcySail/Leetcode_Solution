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
    string customSortString(string S, string T)
    {
        int lens = S.length();
        int lent = T.length();
        int arr[26] = {0};
        for (int i = 0; i < lent; ++i) {
            ++arr[T[i] - 'a'];
        }

        string result;
        for (int i = 0; i < lens; ++i) {
            result += string(arr[S[i] - 'a'], S[i]);
            arr[S[i] - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[i] != 0) {
                result += string(arr[i], 'a' + i);
            }
        }
        return result;
    }
};

int main() { Solution sol; }

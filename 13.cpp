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
    int romanToInt(string s)
    {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        int arr[256] = {0};
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;

        int sum = 0;
        sum = arr[s[len - 1]];
        for (int i = len - 2; i >= 0; --i) {
            if (arr[s[i]] < arr[s[i + 1]]) {
                sum -= arr[s[i]];
            } else {
                sum += arr[s[i]];
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;

    cout << sol.romanToInt("III") << endl;
    cout << sol.romanToInt("IV") << endl;
    cout << sol.romanToInt("IX") << endl;
    cout << sol.romanToInt("LVIII") << endl;
    cout << sol.romanToInt("MCMXCIV") << endl;
}

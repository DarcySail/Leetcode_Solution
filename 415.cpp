#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    string addStrings(string num1, string num2)
    {
        if (num1.length() < num2.length()) {
            num1.swap(num2);
        }
        int len1 = num1.length();
        int len2 = num2.length();
        int i = len1 - 1;
        int carry = 0;
        for (; i >= len1 - len2; --i) {
            int val1 = num1[i] - '0';
            int val2 = num2[i - len1 + len2] - '0';
            val1 = val1 + val2 + carry;
            num1[i] = val1 % 10 + '0';
            carry = val1 / 10;
        }

        for (; i >= 0; --i) {
            int val1 = num1[i] - '0';
            val1 = val1 + carry;
            num1[i] = val1 % 10 + '0';
            carry = val1 / 10;
        }

        if (carry) {
            num1 = string(1, '0' + carry) + num1;
        }

        return num1;
    }
};

int main()
{
    Solution sol;

    cout << sol.addStrings("9", "1") << endl;
    cout << sol.addStrings("19", "1") << endl;
    cout << sol.addStrings("19", "0") << endl;
    cout << sol.addStrings("19", "") << endl;
    cout << sol.addStrings("16", "1") << endl;
}

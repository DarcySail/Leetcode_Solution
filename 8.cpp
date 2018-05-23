#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// brilliant
int atoi(const char *str)
{
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-');
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}
// ugly code...
class Solution
{
  public:
    int myAtoi(string str)
    {
        bool flag = true;
        int start = 0;
        int end = 0;
        long long result = 0;
        long long MY_INT_MAX = INT_MAX;
        while (str[start] == ' ')
            ++start;

        if (str[start] == '+' || str[start] == '-') {
            flag = str[start] == '+';
            end = ++start;
        }
        end = start;
        while (str[end] >= '0' && str[end] <= '9')
            ++end;
        if (start == end) {
            return 0;
        }

        for (; start < end && result <= MY_INT_MAX + 1; ++start) {
            result *= 10;
            result += str[start] - '0';
        }

        if (result >= MY_INT_MAX + 1) {
            result = MY_INT_MAX;
            result = flag ? result : result + 1;
        }
        result = flag ? result : -result;
        return result;
    }
};

int main()
{
    Solution sol;

    cout << sol.myAtoi("43") << endl;
    cout << sol.myAtoi("-43") << endl;
    cout << sol.myAtoi("0") << endl;
    cout << sol.myAtoi("") << endl;
    cout << sol.myAtoi("  -43") << endl;
    cout << sol.myAtoi("-withwor") << endl;
    cout << sol.myAtoi("  -43withwor") << endl;
    cout << sol.myAtoi(" wor -43") << endl;
    cout << sol.myAtoi("91283472332") << endl;
    cout << sol.myAtoi("-91283472332") << endl;
    cout << sol.myAtoi("-2147483648") << endl;
    cout << sol.myAtoi("2147483649") << endl;
    cout << sol.myAtoi("2147483647") << endl;
    cout << sol.myAtoi("-2147483646") << endl;
    cout << sol.myAtoi("9223372036854775808") << endl;
}

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
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        int carry = 0;
        ++digits[len - 1];
        for (int i = len - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main()
{
    int con[] = {9, 9, 9};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    sol.plusOne(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
}

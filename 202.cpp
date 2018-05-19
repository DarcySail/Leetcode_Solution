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
    bool isHappy(int n)
    {
        map<int, bool> dict;
        while (n != 1) {
            if (dict.find(n) != dict.end()) {
                return false;
            }
            int sum = 0;
            int low = 0;
            dict[n] = true;
            while (n > 0) {
                low = n % 10;
                n = n / 10;
                sum += low * low;
            }
            n = sum;
        }

        return true;
    }
};

int main()
{
    int con[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    cout << sol.isHappy(9);
}

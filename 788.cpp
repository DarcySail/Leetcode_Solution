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

// Author: Huahua
// Running time: 21 ms
class Solution
{
  public:
    int isValid(int n)
    {
        string s = to_string(n);
        string t(s);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '3' || s[i] == '4' || s[i] == '7')
                return 0;
            else if (s[i] == '2')
                t[i] = '5';
            else if (s[i] == '5')
                t[i] = '2';
            else if (s[i] == '6')
                t[i] = '9';
            else if (s[i] == '9')
                t[i] = '6';
        }

        return t != s;
    }

    int rotatedDigits(int N)
    {
        int ans = 0;
        for (int i = 1; i <= N; ++i)
            ans += isValid(i);
        return ans;
    }
};

// Author: Huahua
// Running time: 4 ms
class Solution
{
  public:
    int isValid(int n)
    {
        constexpr int kInValidMask = (1 << 3) | (1 << 4) | (1 << 7);
        constexpr int kValidMask = (1 << 2) | (1 << 5) | (1 << 6) | (1 << 9);

        int valid = 0;

        while (n > 0) {
            int r = 1 << (n % 10);
            if (r & kInValidMask)
                return 0;
            else if (r & kValidMask)
                valid = 1;
            n /= 10;
        }

        return valid;
    }

    int rotatedDigits(int N)
    {
        int ans = 0;
        for (int i = 1; i <= N; ++i)
            ans += isValid(i);
        return ans;
    }
};

// stupid dp
class Solution
{
  public:
    bool isX(int i)
    {
        static int arr[256];
        arr['2'] = '5';
        arr['5'] = '2';
        arr['6'] = '9';
        arr['9'] = '6';
        string num = to_string(i);
        for (int i = 0; i < num.length(); ++i) {
            if (num[i] == '3' || num[i] == '4' || num[i] == '7') {
                return false;
            }
            if (num[i] == '5' || num[i] == '2' || num[i] == '6' ||
                num[i] == '9') {
                num[i] = arr[num[i]];
            }
        }
        int X = stoi(num);
        return i != X;
    }

    int rotatedDigits(int N)
    {
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            if (isX(i)) {
                dp[i] = dp[i - 1] + 1;
                cout << i << ' ';
            } else {
                dp[i] = dp[i - 1];
            }
        }

        // print_vector(dp);
        return dp[N];
    }
};

int main()
{
    Solution sol;
    sol.rotatedDigits(10);
}

//        for (int left = 0, right = num.length() - 1; left <= right;
//             ++left, --right) {
//            if (nums[left] == '3' || nums[left] == '4' || nums[left] == '7' ||
//                nums[right] == '3' || nums[right] == '4' ||
//                nums[right] == '7') {
//                return false;
//            }
//            if ((nums[left] == '2' && nums[right] == '5') ||
//                (nums[left] == '5' && nums[right] == '2')) {
//                continue;
//            } else if ((nums[left] == '6' && nums[right] == '9') ||
//                       (nums[left] == '9' && nums[right] == '6')) {
//                continue;
//            } else if (nums[left] == nums[right]) {
//                continue;
//            }
//            return false;
//        }

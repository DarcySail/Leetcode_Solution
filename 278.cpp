#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    if (version < 3)
        return false;
    return true;
}

class Solution
{
  public:
    int firstBadVersion(int n)
    {
        int start = 1, end = n;
        int _count = 0;
        while (start <= end) {
            int mid = start + ((end - start) >> 1);
            // cout << start << ' ' << mid << ' ' << end << endl;
            ++_count;
            if (isBadVersion(mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
                if (start == n) {
                    cout << _count << endl;
                    return start;
                }
            }
        }
        cout << _count << endl;
        return start;
    }
};

class Solution1
{
  public:
    int firstBadVersion(int n)
    {
        int lower = 1, upper = n, mid;
        int _count = 0;
        while (lower < upper) {
            mid = lower + (upper - lower) / 2;
            if (!isBadVersion(mid))
                lower = mid + 1; /* Only one call to API */
            else
                upper = mid;
            ++_count;
        }
        cout << _count << endl;
        return lower;
    }
};

int main()
{
    Solution sol;
    Solution1 sol1;
    sol.firstBadVersion(3);
    sol1.firstBadVersion(3);
}

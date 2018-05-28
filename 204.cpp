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
    int countPrimes(int n)
    {
        vector<bool> arr(n + 1, false);
        for (int i = 2; i < n; ++i) {
            for (long j = 2; j * i < n; ++j) {
                // cout << j << endl;
                long tmp = i * j;
                arr[tmp] = true;
            }
        }
        int _count = 0;
        for (int i = 2; i < n; ++i) {
            if (!arr[i])
                ++_count;
        }
        return _count;
    }
};

int main()
{
    Solution sol;
    cout << sol.countPrimes(300);
}

publib int countPrimes(int n) {
    if (n < 3)
        return 0;

    boolean[] f = new boolean[n];
    //Arrays.fill(f, true); boolean[] are initialed as false by default
    int count = n / 2;
    for (int i = 3; i * i < n; i += 2) {
        if (f[i])
            continue;

        for (int j = i * i; j < n; j += 2 * i) {
            if (!f[j]) {
                --count;
                f[j] = true;
            }
        }
    }
    return count;
}

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
    int numTrees(int n)
    {
        vector<int> arr(n + 1);
        arr[0] = arr[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                arr[i] += arr[j - 1] * arr[i - j];
            }
        }
        return arr[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.numTrees(1) << endl;
    cout << sol.numTrees(2) << endl;
    cout << sol.numTrees(3) << endl;
    cout << sol.numTrees(4) << endl;
}

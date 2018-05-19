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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            result.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
};

int main()
{
    int con[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    vector<vector<int>> rr;
    rr = sol.generate(1);
    for (int i = 0; i < rr.size(); ++i) {
        for (int j = 0; j < rr[i].size(); ++j) {
            cout << rr[i][j] << ' ';
        }
        cout << endl;
    }
}

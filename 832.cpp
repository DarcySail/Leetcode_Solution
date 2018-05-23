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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int row = A.size();
        int col = A[0].size();
        int col_loop = (A[0].size()) >> 1;
        bool flag = A[0].size() & 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col_loop; ++j) {
                int tmp = A[i][j];
                A[i][j] = !A[i][col - 1 - j];
                A[i][col - 1 - j] = !tmp;
            }
            if (flag) {
                A[i][col >> 1] = !A[i][col >> 1];
            }
        }
        return A;
    }
};

int main()
{
    int con[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    Solution sol;
    for (int i = 0; i < 28; ++i)
        cout << i << ' ' << sol.flipAndInvertImage(i) << endl;
}

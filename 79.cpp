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
    bool dfs(vector<vector<char>> &board, string word, int x, int y, int idx)
    {
        if (board[x][y] != word[idx]) {
            return false;
        }
        if (idx == word.length() - 1) {
            return true;
        }
        board[x][y] = -board[x][y];
        static int drct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int to_x = drct[i][0] + x;
            int to_y = drct[i][1] + y;
            if (to_x >= 0 && to_x < board.size() && to_y >= 0 &&
                to_y < board[to_x].size()) {
                if (dfs(board, word, to_x, to_y, idx + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = -board[x][y];
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.length() == 0) {
            return true;
        }
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> mat;
    mat.push_back({'A', 'B', 'C', 'E'});
    mat.push_back({'S', 'F', 'C', 'S'});
    mat.push_back({'A', 'D', 'E', 'E'});
    string str = "SEE";
    cout << sol.exist(mat, str) << endl;
    str = "ABCCED";
    cout << sol.exist(mat, str) << endl;
    str = "ABCB";
    cout << sol.exist(mat, str) << endl;
}

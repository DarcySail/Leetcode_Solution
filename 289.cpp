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
    int judge(vector<vector<int>> &board, int x, int y)
    {
        int up = x - 1 >= 0 ? x - 1 : 0;
        int down = x + 1 <= board.size() - 1 ? x + 1 : board.size() - 1;
        int left = y - 1 >= 0 ? y - 1 : 0;
        int right = y + 1 <= board[x].size() - 1 ? y + 1 : board[x].size() - 1;
        int count_alive_neib = 0;
        for (int i = up; i <= down; ++i) {
            for (int j = left; j <= right; ++j) {
                if (i == x && j == y) {
                    continue;
                }
                if (board[i][j] > 0) {
                    ++count_alive_neib;
                }
            }
        }
        if (count_alive_neib < 2 || count_alive_neib > 3) {
            return board[x][y] == 0 ? -1 : 2;
        } else {
            return board[x][y] == 1 ? 3 : count_alive_neib == 3 ? -2 : -1;
        }
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                board[i][j] = judge(board, i, j);
            }
        }
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == -1 || board[i][j] == 2) {
                    board[i][j] = 0;
                } else {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

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
    bool isSubValid(vector<vector<char>> &board, int x, int y)
    {
        vector<bool> dict(10, false);
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (board[i][j] != '.') {
                    if (dict[board[i][j] - '0']) {
                        return false;
                    }
                    dict[board[i][j] - '0'] = true;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i) {
            vector<bool> dict(10, false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (dict[board[i][j] - '0']) {
                        return false;
                    }
                    dict[board[i][j] - '0'] = true;
                }
            }
        }

        for (int j = 0; j < 9; ++j) {
            vector<bool> dict(10, false);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (dict[board[i][j] - '0']) {
                        return false;
                    }
                    dict[board[i][j] - '0'] = true;
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isSubValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() { Solution sol; }

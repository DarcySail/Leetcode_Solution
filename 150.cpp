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
    int evalRPN(vector<string> &tokens)
    {
        int i = 0;
        while (tokens.size() != 1) {
            if (tokens[i].length() == 1 && !isdigit(tokens[i][0])) {
                int first = stoi(tokens[i - 2]);
                int sec = stoi(tokens[i - 1]);
                switch (tokens[i][0]) {
                case '+':
                    tokens[i - 2] = to_string(first + sec);
                    break;
                case '-':
                    tokens[i - 2] = to_string(first - sec);
                    break;
                case '*':
                    tokens[i - 2] = to_string(first * sec);
                    break;
                case '/':
                    tokens[i - 2] = to_string(first / sec);
                    break;
                }
                tokens.erase(tokens.begin() + i - 1, tokens.begin() + i + 1);
                --i;
            } else {
                ++i;
            }
        }

        return stoi(tokens[0]);
    }
};

int main()
{
    Solution sol;
    vector<string> arr({"2", "1", "+", "3", "*"});
    cout << sol.evalRPN(arr) << endl;
}

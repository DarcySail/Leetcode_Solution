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
    int calPoints(vector<string> &ops)
    {
        vector<int> stack;
        int sum = 0;
        int val = 0;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i][0] == '+') {
                val = stack[stack.size() - 1] + stack[stack.size() - 2];
                sum += val;
                stack.push_back(val);
            } else if (ops[i][0] == 'D') {
                val = stack[stack.size() - 1] * 2;
                sum += val;
                stack.push_back(val);
            } else if (ops[i][0] == 'C') {
                sum -= stack[stack.size() - 1];
                stack.pop_back();
            } else {
                val = stoi(ops[i]);
                sum += val;
                stack.push_back(val);
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;

    cout << sol.(1) << endl;
}

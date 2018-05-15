#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class MinStack
{
  public:
    vector<int> cur_min;
    vector<int> min_stack;
    int min_val;
    /** initialize your data structure here. */
    MinStack() { min_val = INT_MAX; }

    void push(int x)
    {
        int min_idx;
        min_stack.push_back(x);
        if (min_val > x) {
            min_val = x;
            min_idx = min_stack.size() - 1;
            cur_min.push_back(min_idx);
        } else {
            min_idx = cur_min[cur_min.size() - 1];
            cur_min.push_back(min_idx);
        }
        // for (int i = 0; i < min_stack.size(); ++i) {
        //    cout << min_stack[i] << ' ';
        //}
        // cout << endl;
        // for (int i = 0; i < min_stack.size(); ++i) {
        //    cout << cur_min[i] << ' ';
        //}
        // cout << endl
        //     << "val: " << min_val << " ,idx: " << cur_min[cur_min.size() - 1]
        //     << endl
        //     << endl;
    }

    void pop()
    {
        min_stack.pop_back();
        cur_min.pop_back();
        if (min_stack.size() == 0) {
            min_val = INT_MAX;
        } else {
            min_val = min_stack[cur_min[cur_min.size() - 1]];
        }
        //for (int i = 0; i < min_stack.size(); ++i) {
        //    cout << min_stack[i] << ' ';
        //}
        //cout << endl;
        //for (int i = 0; i < min_stack.size(); ++i) {
        //    cout << cur_min[i] << ' ';
        //}
        //cout << endl
        //     << "val: " << min_val << " ,idx: " << cur_min[cur_min.size() - 1]
        //     << endl
        //     << endl;
    }

    int top()
    {
        if (min_stack.size() == 0)
            return 0;
        return min_stack[min_stack.size() - 1];
    }

    int getMin()
    {
        if (min_stack.size() == 0)
            return 0;
        return min_val;
    }
};

int main()
{
    MinStack *minStack = new MinStack();
    int x = 9;
    minStack->push(-10);
    minStack->push(14);
    minStack->push(-20);
    minStack->pop();
    minStack->push(10);
    minStack->push(-7);
    minStack->push(-7);
    minStack->pop();
    cout << minStack->getMin() << endl;
    // for (int i = 0; i < minStack->min_stack.size(); ++i) {
    //    cout << minStack->min_stack[i] << ' ';
    //}
    // cout << endl;
    // for (int i = 0; i < minStack->min_stack.size(); ++i) {
    //    cout << minStack->cur_min[i] << ' ';
    //}
    minStack->pop();
    // cout << minStack->top() << endl;
}

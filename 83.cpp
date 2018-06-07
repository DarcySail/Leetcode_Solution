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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *it = head;
        while (it && it->next) {
            if (it->val == it->next->val) {
                it->next = it->next->next;
            } else {
                it = it->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

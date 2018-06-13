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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *odd = head, *even = head->next, *even_head = head->next;
        ListNode *it = even->next;
        int cur_idx = 2;
        for (; it != NULL; ++cur_idx, it = it->next) {
            if (cur_idx & 1) {
                even->next = it;
                even = it;
            } else {
                odd->next = it;
                odd = it;
            }
        }
        odd->next = even_head;
        if (cur_idx & 1) {
            even->next = NULL;
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

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

void print_list(ListNode *head)
{
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

class Solution
{
  public:
    ListNode *reverseList(ListNode *head, int n)
    {
        int i = 0;
        ListNode *it = head;
        ListNode *last = NULL;
        ListNode *cur = NULL;
        while (it && i < n) {
            cur = it;
            it = it->next;
            cur->next = last;
            last = cur;
            ++i;
        }
        head->next = it;

        return last;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k < 2) {
            return head;
        }
        ListNode *it = head;
        ListNode *result;
        int i = 0;

        for (; i < k && it != NULL; ++i, it = it->next);
        if (i != k) {
            return head;
        }
        result = reverseList(head, k);
        head->next = reverseKGroup(head->next, k);

        return result;
    }
};

int main()
{
    Solution sol;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    // b.next = &c;
    // c.next = &d;
    // d.next = &e;
    ListNode *p = sol.reverseKGroup(&a, 3);
    print_list(p);
}

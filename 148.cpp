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

// ugly code
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }

        ListNode *it1, *it2, *last, *l2_next;
        ListNode head(0);
        head.next = l1;
        last = &head;
        it1 = l1, it2 = l2;
        while (it2) {
            if (!it1) {
                last->next = it2;
                break;
            }
            if (it1->val < it2->val) {
                last = it1;
                it1 = it1->next;
            } else if (it1->val >= it2->val) {
                l2_next = it2->next;
                last->next = it2;
                it2->next = it1;
                last = it2;
                it2 = l2_next;
            }
        }

        return head.next;
    }

    ListNode *cutHalf(ListNode *head)
    {
        if (!head) {
            return NULL;
        }
        ListNode *fast = head, *slow = head;
        for (; fast; slow = slow->next) {
            fast = fast->next;
            if (fast && fast->next) {
                fast = fast->next;
            } else {
                break;
            }
        }
        ListNode *sec = slow->next;
        slow->next = NULL;
        return sec;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *first_half_head = cutHalf(head);
        ListNode *first = sortList(head);
        ListNode *sec = sortList(first_half_head);
        return mergeTwoLists(first, sec);
    }
};

int main()
{
    Solution sol;
    ListNode a(4);
    ListNode b(2);
    ListNode c(1);
    ListNode d(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    sol.sortList(&a);
}

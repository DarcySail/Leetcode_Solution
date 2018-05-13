#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }

        ListNode *it1, *it2, *last, *l2_next;
        ListNode head(0);
        head.next = l1;
        last = &head;
        it1 = l1, it2 = l2, last;
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
};

int main()
{
    Solution sol;
    ListNode root1(1);
    ListNode root2(2);
    ListNode root3(4);
    root1.next = &root2;
    root2.next = &root3;

    ListNode lroot1(1);
    ListNode lroot2(3);
    ListNode lroot3(4);
    lroot1.next = &lroot2;
    lroot2.next = &lroot3;
    sol.mergeTwoLists(&root1, &lroot1);
}
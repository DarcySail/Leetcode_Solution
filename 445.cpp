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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int len1 = 0, len2 = 0;
        for (ListNode *it = l1; it != NULL; ++len1, it = it->next)
            ;
        for (ListNode *it = l2; it != NULL; ++len2, it = it->next)
            ;

        if (len1 < len2) {
            swap(l1, l2);
            swap(len1, len2);
        }
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode *it1, *it2;
        for (it1 = l1, it2 = l2; it1 != NULL && it2 != NULL;
             it1 = it1->next, it2 = it2->next) {
            it1->val += carry + it2->val;
            carry = it1->val / 10;
            it1->val %= 10;
        }

        for (; it1 != NULL; it1 = it1->next) {
            it1->val += carry;
            carry = it1->val / 10;
            it1->val %= 10;
        }

        l1 = reverseList(l1);
        if (carry) {
            ListNode *p = new ListNode(carry);
            p->next = l1;
            l1 = p;
        }

        return l1;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *it = head;
        ListNode *last = NULL;
        ListNode *cur = NULL;
        while (it) {
            cur = it;
            it = it->next;
            cur->next = last;
            last = cur;
        }
        return last;
    }
};

int main() { Solution sol; }

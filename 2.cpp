#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
        int len1, len2, tmp, i;
        len1 = len2 = 0;
        vector<int> num1, num2;
        ListNode *result;
        ListNode *cur;
        ListNode *tmp_node;
        ListNode *beg;
        ListNode *last;
        for (beg = l1; beg != NULL; beg = beg->next) {
            ++len1;
        }
        for (beg = l2; beg != NULL; beg = beg->next) {
            ++len2;
        }
        if (len1 < len2) {
            tmp_node = l1;
            l1 = l2;
            l2 = tmp_node;
            tmp = len1;
            len1 = len2;
            len2 = tmp;
        }

        int carry = 0;
        for (i = 0, beg = l1, last = NULL; i < len2;
             ++i, last = beg, beg = beg->next, l2 = l2->next) {
            beg->val += carry;
            carry = 0;
            beg->val = beg->val + l2->val;
            if (beg->val > 9) {
                carry = beg->val / 10;
                beg->val = beg->val % 10;
            }
        }
        for (; beg != NULL; last = beg, beg = beg->next) {
            beg->val += carry;
            carry = 0;
            if (beg->val > 9) {
                carry = beg->val / 10;
                beg->val = beg->val % 10;
            }
        }

        if (carry != 0) {
            ListNode *tmp = new ListNode(carry);
            last->next = tmp;
        }
        return l1;
    }
};

int main()
{
    ListNode a(9);
    ListNode b(8);
    ListNode c(3);
    ListNode d(9);
    a.next = &b;
    //b.next = &c;
    //c.next = &d;

    ListNode e(1);
    ListNode f(6);
    ListNode g(4);
    ListNode h(9);
    //e.next = &f;
    //f.next = &g;
    //g.next = &h;
    Solution sol;
    ListNode *ans = sol.addTwoNumbers(&a, &e);
    for (ListNode *beg = ans; beg; beg = beg->next) {
        cout << beg->val << " " << endl;
    }
}
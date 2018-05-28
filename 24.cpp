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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode foo(0);
        foo.next = head;

        ListNode *it = &foo;
        while (it->next != NULL && it->next->next != NULL) {
            ListNode *first = it->next;
            ListNode *second = it->next->next;
            first->next = second->next;
            second->next = first;
            it->next = second;
            it = first;
        }

        return foo.next;
    }
};

int main() { Solution sol; }

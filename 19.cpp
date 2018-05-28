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
    ListNode *helper(ListNode *head, int &n)
    {
        if (head == NULL) {
            return NULL;
        }
        helper(head->next, n);
        if (n == 0) {
            head->next = head->next->next;
        }

        n = n - 1;
        return head;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL) {
            return NULL;
        }
        ListNode foo(0);
        foo.next = head;
        helper(&foo, n);
        return foo.next;
    }
};

int main() { Solution sol; }

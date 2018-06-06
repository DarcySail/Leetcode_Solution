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
    ListNode *reverseList(ListNode *head, int n)
    {
        if (n <= 1) {
            return head;
        }
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == NULL) {
            return head;
        }
        int len = 0, i = 0;
        ListNode *it = head;
        for (; it != NULL; ++len, it = it->next) ;

        k = k % len;
        head = reverseList(head, len - k);

        it = head;
        for (; i < len - k - 1 && it != NULL; ++i, it = it->next) ;
        it->next = reverseList(it->next, k);
        head = reverseList(head, len);

        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({1});
    sol.isOneBitCharacter(arr);
}

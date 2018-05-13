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

// recursive
class Solution
{
  public:
    ListNode *reverseList(ListNode *head) { return _reverseList(head, NULL); }
    static ListNode *_reverseList(ListNode *it, ListNode *last)
    {
        ListNode *cur = NULL;
        if (!it) {
            return last;
        }

        cur = it;
        it = it->next;
        cur->next = last;
        last = cur;

        return _reverseList(it, last);
    }
};

// iterator
// class Solution
//{
//  public:
//    ListNode *reverseList(ListNode *head)
//    {
//        ListNode *it = head;
//        ListNode *last = NULL;
//        ListNode *cur = NULL;
//        while (it) {
//            cur = it;
//            it = it->next;
//            cur->next = last;
//            last = cur;
//        }
//
//        return last;
//    }
//};

int main()
{
    Solution sol;
    cout << sol.countSubstrings(b) << endl;
}
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
class Solution // 34ms
{
  public:
    static bool heapComp(ListNode *a, ListNode *b) { return a->val > b->val; }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    { // make_heap
        ListNode head(0);
        ListNode *curNode = &head;
        vector<ListNode *> v;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                v.push_back(lists[i]);
        }
        make_heap(v.begin(), v.end(), heapComp); // vector -> heap data strcture

        while (v.size() > 0) {
            curNode->next = v.front();
            pop_heap(v.begin(), v.end(), heapComp);
            v.pop_back();
            curNode = curNode->next;
            if (curNode->next) {
                v.push_back(curNode->next);
                push_heap(v.begin(), v.end(), heapComp);
            }
        }
        return head.next;
    }
};

class Solution
{
  private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) // 284ms
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

  public:
    ListNode *mergeKLists1(vector<ListNode *> &lists)
    {
        ListNode *ret = NULL;
        for (int i = 0; i < lists.size(); ++i) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }

    ListNode *helper(vector<ListNode *> &lists, int start, int end) // 32ms
    {
        if (end == start) {
            return lists[start];
        }
        ListNode *left = helper(lists, start, start + (end - start) / 2);
        ListNode *right = helper(lists, start + (end - start) / 2 + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0) {
            return NULL;
        }
        return helper(lists, 0, lists.size() - 1);
    }
};

int main() { Solution sol; }

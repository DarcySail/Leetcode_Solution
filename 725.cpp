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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        ListNode *it = root, *last = NULL;
        vector<ListNode *> result;
        int len = 0, j = 0;
        for (; it != NULL; ++len, it = it->next)
            ;

        int quotient = len / k, remainder = len % k;
        it = root;
        for (int i = 0; i < remainder; ++i) {
            result.push_back(it);
            for (j = 0; j < quotient + 1; ++j, last = it, it = it->next)
                ;
            last->next = NULL;
        }

        for (int i = 0; i < k - remainder; ++i) {
            result.push_back(it);
            for (j = 0; j < quotient; ++j, last = it, it = it->next)
                ;
            if (last) {
                last->next = NULL;
            }
        }

        return result;
    }
};

int main() { Solution sol; }

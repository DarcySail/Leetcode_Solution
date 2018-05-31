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

class Solution
{
  public:
    int numComponents(ListNode *head, vector<int> &G)
    {
        unordered_set<int> dict(10000);
        for (auto i : G) {
            dict.insert(i);
        }

        int ans = 0;
        while (head) {
            bool flag = false;
            while (head && dict.find(head->val) == dict.end()) {
                head = head->next;
            }
            while (head && dict.find(head->val) != dict.end()) {
                flag = true;
                head = head->next;
            }
            ans = flag ? ans + 1 : ans;
        }

        return ans;
    }
};

int main() { Solution sol; }

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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head) {
            return NULL;
        }
        RandomListNode *it;
        unordered_map<RandomListNode *, RandomListNode *> dict;
        for (it = head; it != NULL; it = it->next) {
            dict[it] = new RandomListNode(it->label);
        }

        for (it = head; it != NULL; it = it->next) {
            dict[it]->random = dict[it->random];
            dict[it]->next = dict[it->next];
        }

        return dict[head];
    }
};

int main() { Solution sol; }

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
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        if (rooms.size() == 1) {
            return true;
        }
        vector<int> queue = rooms[0];
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        while (queue.size()) {
            int val = queue[0];
            if (!visited[val]) {
                queue.insert(queue.end(), rooms[val].begin(),
                             rooms[val].end());
                visited[val] = true;
            }
            queue.erase(queue.begin());
        }
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() { Solution sol; }

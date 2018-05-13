#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int result = 0;
        int type = 0;
        int min_task = 10001;
        int arr[26] = {0};
        for (int i = 0; i < tasks.size(); ++i) {
            ++arr[tasks[i] - 'A'];
        }
        for (int i = 0; i < 26; ++i) {
            type = arr[i] ? type + 1 : type;
            min_task = min_task < arr[i] ? min_task : arr[i];
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    char con[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> arr(con, con + sizeof(con) / sizeof(char));
    cout << sol.leastInterval(arr, 2);
}

// class Solution
//{
//  public:
//    int leastInterval(vector<char> &tasks, int n)
//    {
//        int result = 0;
//        map<char, int> dict;
//        map<int, vector<char>> rev_dict;
//        for (int i = 0; i < tasks.size(); ++i) {
//            dict[tasks[i]]++;
//        }
//        map<char, int>::iterator it = dict.begin();
//        for (; it != dict.end(); ++it) {
//            rev_dict[it->second].push_back(it->first);
//        }
//
//        return 0;
//    }
//};
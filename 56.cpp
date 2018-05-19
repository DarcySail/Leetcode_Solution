#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
  public:
    static bool cmp(Interval a, Interval b)
    {
        if (a.end == b.end)
            return a.start < b.start;
        return a.end < b.end;
    }

    vector<Interval> merge(vector<Interval> &intervals)
    {
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = len - 2; i >= 0; --i) {
            if (intervals[i].end >= intervals[i + 1].start) {
                int lstart = intervals[i].start;
                int rstart = intervals[i + 1].start;
                intervals[i].start = lstart < rstart ? lstart : rstart;
                int lend = intervals[i].end;
                int rend = intervals[i + 1].end;
                intervals[i].end = lend > rend ? lend : rend;
                intervals.erase(intervals.begin() + i + 1);
            }
        }

        return intervals;
    }
};

int main()
{
    Solution sol;
    // cout << sol.() << endl;
}

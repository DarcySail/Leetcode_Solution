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
    int helper(vector<int> &arr, int beg, int end)
    {
        while (beg < end) {
            int mid = beg + ((end - beg) >> 1);
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) {
                beg = mid + 1;
            } else if (arr[mid - 1] > arr[mid]) {
                end = mid - 1;
            }
        }
        return beg;
    }
    int peakIndexInMountainArray(vector<int> &A)
    {
        int len = A.size();
        int result = helper(A, 0, len - 1);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr({0, 2, 1, 0});
    cout << sol.peakIndexInMountainArray(arr) << endl;
    vector<int> arr2({0, 1, 2, 0});
    cout << sol.peakIndexInMountainArray(arr2) << endl;
}

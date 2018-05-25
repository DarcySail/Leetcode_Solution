#include <algorithm>
#include <climits>
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1, end = nums1.size() - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[end--] = nums1[p1--];
            } else {
                nums1[end--] = nums2[p2--];
            }
        }

        while (p2 >= 0) {
            nums1[end--] = nums2[p2--];
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr1({0, 0, 3, 0, 0, 0, 0, 0, 0});
    vector<int> arr2({-1, 1, 1, 1, 2, 3});
    sol.merge(arr1, 3, arr2, 6);
}

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
    static int binary_search(vector<int> arr, int key, int start, int end)
    {
        int ret = -1; // 未搜索到数据返回-1下标

        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2; //直接平均可能會溢位，所以用此算法
            if (arr[mid] < key)
                start = mid + 1;
            else if (arr[mid] > key)
                end = mid - 1;
            else { // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
                ret = mid;
                break;
            }
        }

        return ret; // 单一出口
    }
    static int helper(vector<int> &arr, int target, int start, int end)
    {
        if (start > end)
            return -1;
        int mid = start + (end - start) / 2;
        if (arr[start] > arr[mid]) {
            int left = helper(arr, target, start, mid);
            int right = binary_search(arr, target, mid + 1, end);
            return left != -1 ? left : right;
        } else {
            int left = binary_search(arr, target, start, mid);
            int right = helper(arr, target, mid + 1, end);
            return left != -1 ? left : right;
        }
    }
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 0) {
            return -1;
        }

        return helper(nums, target, 0, len - 1);
    }
};

int main()
{
    Solution sol;
    //int con[] = {4, 5, 6, 7, 0, 1, 2};
    int con[] = {4,5,6,7,0,1,2};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    cout << sol.search(arr, 3) << endl;
}
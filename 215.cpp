#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void min_heapify(vector<int> &arr, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son])
            return;
        else {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

int heap_sort(vector<int> &arr, int len, int k)
{
    int i;
    for (i = len / 2 - 1; i >= 0; i--)
        min_heapify(arr, i, len - 1);

    for (i = len - 1; i > len - 1 - k; i--) {
        swap(&arr[0], &arr[i]);
        min_heapify(arr, 0, i - 1);
    }
    return arr[len - k];
}

class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return heap_sort(nums, nums.size(), k);
    }
};

int main()
{
    Solution sol;
    int arr[] = {3, 2, 1, 5, 6, 4};
    vector<int> con(arr, arr + sizeof(arr) / sizeof(int));

    cout << sol.findKthLargest(con, 2);
}

// while (start != k - 1) {
//    while (start < end) {
//        if (nums[start] > cur_val) {
//            int swap_val = nums[start];
//            nums[start] = nums[end];
//            nums[end++] = swap_val;
//        } else {
//            ++start;
//        }
//    }
//}

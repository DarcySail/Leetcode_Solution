#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int cur_area = 0;
        int min_height = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                min_height = height[left];
                cur_area = min_height * (right - left);
                ++left;
            } else {
                min_height = height[right];
                cur_area = min_height * (right - left);
                --right;
            }
            max_area = max_area > cur_area ? max_area : cur_area;
        }

        return max_area;
    }
};

int main()
{
    int tmp[] = {1, 3, 4, 1};
    vector<int> arr(tmp, tmp + sizeof(tmp) / sizeof(int));
    Solution sol;
    cout << sol.maxArea(arr);
}
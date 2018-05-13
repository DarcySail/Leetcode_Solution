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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size();) {
            if (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                //cout << i << ": " << nums[i] << "  ==    ";
                //cout << nums[i] + 1 << ": " << nums[nums[i] + 1] << endl;
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int con[] = {4, 3, 2, 7, 8, 2, 3, 1};
    //int con[] = {1, 3, 4, 1};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    arr = sol.findDisappearedNumbers(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
}
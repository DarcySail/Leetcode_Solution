#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int complement;
        vector<int> result;
        map<int, int> con;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            complement = target - nums[i];
            it = con.find(complement);
            if (it != con.end()) {
                result.push_back(i);
                result.push_back(con[complement]);
                return result;
            }
            con[nums[i]] = i;
        }
    }
};

int main()
{
    Solution a;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(11);
    arr.push_back(15);
    arr.push_back(9);
    arr.push_back(7);
    int val = 9;
    vector<int> b = a.twoSum(arr, val);
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << endl;
    }
}
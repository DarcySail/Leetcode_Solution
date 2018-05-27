#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include <pair>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            int res = nums[l] + nums[r] - target;
            while (l < r) {
                if (res < 0) {
                    ++l;
                } else if (res > 0) {
                    --r;
                } else {
                    // cout << i << ' ' << l << ' ' << r << endl;
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++l])
                        ;
                    while (l < r && nums[r] == nums[--r])
                        ;
                    // cout << "a " << i << ' ' << l << ' ' << r << endl;
                }
                res = nums[l] + nums[r] - target;
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                ++i;
        }
        return result;
    }
};

int main()
{

    int arr[] = {-4, -1, 0, 1, 2, -1, 0, -4};
    vector<int> con(arr, arr + sizeof(arr) / sizeof(int));
    Solution sol;
    vector<vector<int>> result = sol.threeSum(con);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}
//        unique(nums.begin(), nums.end());
//
//        for (int i = 0; i < nums.size(); ++i) {
//            int complement = -nums[i];
//            if (two_sum.find(complement) != two_sum.end()) {
//
//                set<pair<int, int> >::iterator set_it =
//                    two_sum[complement].begin();
//                for (; set_it != two_sum[complement].end(); ++set_it) {
//                vector<int> tmp;
//                    tmp.push_back(nums[i]);
//                    tmp.push_back(set_it->first);
//                    tmp.push_back(set_it->second);
//                result.push_back(tmp);
//                }
//            }
//        }
//        // map<int, set<pair<int, int> > >::iterator it =
//        // two_sum.begin();
//        // for (; it != two_sum.end(); ++it) {
//        //    //cout << "base = " << it->first << endl;
//        //    set<pair<int, int> >::iterator set_it =
//        //    it->second.begin();
//        //    for (; set_it != it->second.end(); ++set_it) {
//        //        //cout << "     " << set_it->first << ' ' <<
//        //        set_it->second
//        //             //<< endl;
//        //    }
//        //}

// class Solution
//{
//  public:
//    vector<vector<int>> threeSum(vector<int> &nums)
//    {
//        map<int, pair<int, int>> two_sum;
//        vector<vector<int>> result;
//
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                // cout<<nums[i] <<' '<<nums[j]<<endl;
//                auto it = two_sum.find(-nums[j]);
//                if (it != two_sum.end()) {
//                    //if ((it->second).first != j && (it->second).second != j)
//                    {
//                        result.push_back({nums[j], nums[it->second.first],
//                                          nums[it->second.second]});
//                    //}
//                }
//                two_sum[nums[i] + nums[j]] = (pair<int, int>(i, j));
//            }
//        }
//        return result;
//    }
//};
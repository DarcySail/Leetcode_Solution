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
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // for (int i = 0; i < nums.size(); ++i) {
        //    cout << nums[i] << ' ';
        //}

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> cur_set = num_subsets(nums, i);
            // for (int n = 0; n < cur_set.size(); ++n) {
            //    for (int m = 0; m < cur_set[n].size(); ++m) {
            //        cout << cur_set[n][m] << ' ';
            //    }
            //    cout << endl;
            //}

            for (int j = 0; j < cur_set.size(); ++j) {
                result.push_back(cur_set[j]);
            }
        }

        return result;
    }

    static vector<vector<int>> num_subsets(vector<int> set, int num)
    {
        if (num == 1) {
            vector<vector<int>> single_elmnt;
            for (int i = 0; i < set.size(); ++i) {
                cout << set[i] << ' ';
                single_elmnt.push_back(vector<int>(1, set[i]));
            }
            cout << endl;
        }
        return vector<vector<int>>();
        vector<vector<int>> return_sets;
        int choosen_val = 0;
        for (int i = 0; i < set.size(); ++i) {
            choosen_val = set[i];
            vector<int> subset(set);
            subset.erase(subset.begin(), subset.begin() + i + 1);
            return_sets = num_subsets(subset, num - 1);
            for (int j = 0; j < return_sets.size(); ++j) {
                return_sets[j].push_back(choosen_val);
            }
        }
        return return_sets;
    }
};

int main()
{
    Solution sol;
    int con[] = {1, 2, 3};
    vector<int> arr(con, con + sizeof(con) / sizeof(int));
    vector<vector<int>> ans = sol.subsets(arr);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
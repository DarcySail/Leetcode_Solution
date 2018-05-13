#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
//#include <pair>

using namespace std;

class Solution
{
  public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        map<int, set<pair<int, int> > > two_sum;
        vector<vector<int> > result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                // cout<<nums[i] <<' '<<nums[j]<<endl;
                two_sum[nums[i] + nums[j]].insert(
                    pair<int, int>(nums[i], nums[j]));
            }
        }
        unique(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int complement = -nums[i];
            if (two_sum.find(complement) != two_sum.end()) {

                set<pair<int, int> >::iterator set_it =
                    two_sum[complement].begin();
                for (; set_it != two_sum[complement].end(); ++set_it) {
                vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(set_it->first);
                    tmp.push_back(set_it->second);
                result.push_back(tmp);
                }
            }
        }
        // map<int, set<pair<int, int> > >::iterator it =
        // two_sum.begin();
        // for (; it != two_sum.end(); ++it) {
        //    //cout << "base = " << it->first << endl;
        //    set<pair<int, int> >::iterator set_it =
        //    it->second.begin();
        //    for (; set_it != it->second.end(); ++set_it) {
        //        //cout << "     " << set_it->first << ' ' <<
        //        set_it->second
        //             //<< endl;
        //    }
        //}
        return result;
    }
};

int main()
{

    int arr[] = {-4, -1, 0, 1, 2, -1, 0, -4};
    vector<int> con(arr, arr + sizeof(arr) / sizeof(int));
    Solution sol;
    vector<vector<int> > result = sol.threeSum(con);
	for(int i = 0; i < result.size(); ++i)
	{
		for(int j = 0; j < result[i].size(); ++j)
		{
			cout<<result[i][j]<<' ';
		}
		cout<<endl;
	}
}
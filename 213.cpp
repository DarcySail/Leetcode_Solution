class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		if(nums.size() == 1) return nums[0];
		vector<int> arr1(nums.begin(), nums.end() - 1), arr2(nums.begin() + 1, nums.end());
		int ans1 = _rob(arr1), ans2 = _rob(arr2);
		return ans1 > ans2 ? ans1 : ans2;
    }
    int _rob(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		if(nums.size() == 1) return nums[0];
		int len = nums.size();
		vector<int> dp(nums);

		for(int i = 2; i < len; ++i)
		{
			int max = 0;
			for(int j = i - 2; j >= 0; --j)
				max = max > dp[j] ? max : dp[j];
			dp[i] += max;
		}
		return dp[len - 2] > dp[len - 1] ? dp[len - 2] : dp[len - 1];		
    }
};
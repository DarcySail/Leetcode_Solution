class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		int size = nums.size(), max_sub_set = 0, index_max = 0, i, j;
		vector<int> result, dp(size, 0), father;
		if(nums.size() == 0) return result;
		
		for(i = 0; i < size; ++i)
			father.push_back(i);

		sort(nums.begin(), nums.end());

		for(i = 1; i < size; ++i)
			for(j = i - 1; j >= 0; --j)
				if(nums[i] % nums[j] == 0 && dp[i] <= dp[j] + 1)
					dp[i] = dp[j] + 1, father[i] = j;

		for(i = 0; i < size; ++i)
			if(dp[i] > max_sub_set)
				max_sub_set = dp[i], index_max = i;

		for(i = index_max; i != father[i]; i = father[i])
			result.push_back(nums[i]);
		result.push_back(nums[i]);

		return result;
    }
};
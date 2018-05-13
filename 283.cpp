class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> zero_count;
		int i = 0, j = 0;
		while(nums[i] == 0) ++i;
		for(; i < nums.size(); ++i)
		{
			if(nums[i] != 0)
			{
				nums[j] = nums[i];
				++j;
			}
		}

		for(; j < nums.size(); ++j)
			nums[j] = 0;
    }
};
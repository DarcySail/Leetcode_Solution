class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0], abs_max = nums[0], product = max, abs_pro = nums[0];
		for(int i = 1; i < nums.size(); ++i)
		{
			product = product <= 0 ? nums[i] : product * nums[i];
			abs_pro = abs_pro == 0 ? nums[i] : abs_pro * nums[i];

			max = product > max ? product : max;
			abs_max = abs(abs_max) <= abs(abs_pro) ? abs_pro : abs_max;

			max = abs_max > 0 ? abs_max : max;
		}
		
		
		int tmp = max;
		max = nums[nums.size() - 1], abs_max = max, product = max, abs_pro = max;
		for(int i = nums.size() - 2; i >= 0; --i)
		{
			product = product <= 0 ? nums[i] : product * nums[i];
			abs_pro = abs_pro == 0 ? nums[i] : abs_pro * nums[i];

			max = product > max ? product : max;
			abs_max = abs(abs_max) <= abs(abs_pro) ? abs_pro : abs_max;

			max = abs_max > 0 ? abs_max : max;
		}
		return max > tmp ? max : tmp;
    }
};
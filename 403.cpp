class Solution {
public:
	bool canCross(vector<int>& stones) {
		int size = stones.size();
		map<int, set<int>> dp;
		set<int>::iterator it;
		dp[0].insert(0);
		dp[1].insert(1);

		for(int i = 1; i < size; ++i)
		{
			int tmp = stones[i];
			for(it = dp[tmp].begin(); it != dp[tmp].end(); ++it)
			{
				dp[tmp + *it - 1].insert(*it - 1);
				dp[tmp + *it].insert(*it);
				dp[tmp + *it + 1].insert(*it + 1);
			}	
		}
		return dp.end() != dp.find(stones[size - 1]) && dp[stones[size - 1]].size();
	}
};
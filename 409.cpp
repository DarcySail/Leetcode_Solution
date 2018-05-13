class Solution {
public:
    int longestPalindrome(string s) {
		int result = 0;
		int num_of_odd = 0;
		int len = s.length();
		map<char, int> count_alpha_num;
		for(int i = 0; i < len; ++i)
		{
			if(count_alpha_num.find(s[i]) == count_alpha_num.end())
				count_alpha_num[s[i]] = 1;
			else
				++count_alpha_num[s[i]];
		}
		for(map<char, int>::iterator it = count_alpha_num.begin(); it != count_alpha_num.end(); ++it)
		{
			if(it->second % 2 == 0)
				result += it->second;
			else
			{
				result += it->second - 1;
				++num_of_odd;
			}
		}
		result += num_of_odd ? 1 : 0;
		return result;
    }
};
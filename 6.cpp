class Solution {
public:
	string convert(string s, int numRows) {
		if(numRows == 1 || s.length() == 0) return s;
		int len = s.length();
		int numSet = numRows * 2 - 2;
		string result;
		vector<string> con;
		for(int i = 0; i < numRows; ++i)
			con.push_back(string());
		for(int i = 0; i < len; ++i)
		{
			int tmp = i % numSet;
			if(tmp < numRows)
				con[tmp] += s[i];
			else
				con[numSet - tmp] += s[i];
		}
		for(int i = 0; i < con.size(); ++i)
			result += con[i];
		return result;
	}
};
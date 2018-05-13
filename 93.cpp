bool assisst(string str1, string str2, string str3, string str4)
{
	if(atoi(str1.c_str()) > 255 || atoi(str2.c_str()) > 255 || atoi(str3.c_str()) > 255 || atoi(str4.c_str()) > 255)
		return false;
	if(str1.length() != 1 && str1[0] == '0')
		return false;
	if(str2.length() != 1 && str2[0] == '0')
		return false;
	if(str3.length() != 1 && str3[0] == '0')
		return false;
	if(str4.length() != 1 && str4[0] == '0')
		return false;
	return true;
}

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		map<string, bool> checkDumpli;
		int len = s.length();
		//invalid case
		if(len > 12 || len < 4) return result;
		string str1, str2, str3, str4;//四个切分子串转化为数字

		//valid case
		for(int i = 1; i < len; ++i)
			for(int j = i + 1; j < len; ++j)
				for(int n = j + 1; n < len; ++n)
				{
					if(i > 3 || j - i > 3 || n - j > 3 || len - n > 3)//切分长度超过3
						continue;
					str1 = s.substr(0, i).c_str();
					str2 = s.substr(i, j - i).c_str();
					str3 = s.substr(j, n - j).c_str();
					str4 = s.substr(n, len - n).c_str();

					//判断是否合法
					if(assisst(str1, str2, str3, str4))
					{
						string tmp;
						tmp += str1; tmp += ".";
						tmp += str2; tmp += ".";
						tmp += str3; tmp += ".";
						tmp += str4;
						if(checkDumpli.end() == checkDumpli.find(tmp))
						{
							checkDumpli[tmp] = 1;
							result.push_back(tmp);
						}
					}
				}
				return result;
	}
};
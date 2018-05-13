class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> con;
		for(int i = 0; i < magazine.length(); ++i)
			if(con.end() == con.find(magazine[i]))
				con[magazine[i]] = 1;
			else
				++con[magazine[i]];
		for(int i = 0; i < ransomNote.length(); ++i)
		{
			if(con.end() == con.find(ransomNote[i]))
				return false;
			else if(con[ransomNote[i]] == 0)
				return false;
			else
				--con[ransomNote[i]];
		}
		return true;
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26];
		memset(arr, 0, 26 * sizeof(int));
		for(int i = 0; i < s.length(); ++i)
			++arr[s[i] - 'a'];

		for(int i = 0; i < s.length(); ++i)
			if(arr[s[i] - 'a'] == 1)
				return i;
		return -1;
    }
};
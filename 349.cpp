class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
		map<int, bool> con, intersect;
		for(int i = 0; i < nums1.size(); ++i)
			con[nums1[i]] = true;
		for(int i = 0; i < nums2.size(); ++i)
			if(con.end() != con.find(nums2[i]))
				intersect[nums2[i]] = true;
		for(map<int, bool>::iterator it = intersect.begin(); it != intersect.end(); ++it)
			result.push_back(it->first);
		return result;
    }
};
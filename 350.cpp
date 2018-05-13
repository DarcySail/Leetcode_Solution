class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		map<int, int> con1, con2;
		for(int i = 0; i < nums1.size(); ++i)
			if(con1.end() == con1.find(nums1[i]))
				con1[nums1[i]] = 1;
			else
				++con1[nums1[i]];

		for(int i = 0; i < nums2.size(); ++i)
			if(con2.end() == con2.find(nums2[i]))
				con2[nums2[i]] = 1;
			else
				++con2[nums2[i]];


			for(map<int, int>::iterator it = con1.begin(); it != con1.end(); ++it)
			{
				if(con2.end() != con2.find(it->first))//exist
				{
					int min = it->second < con2[it->first] ? it->second : con2[it->first];
					for(int i = 0; i < min; ++i)
						result.push_back(it->first);
				}
			}
			return result;
	}
};
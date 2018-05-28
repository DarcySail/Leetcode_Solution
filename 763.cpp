#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> partitionLabels(string S)
    {
        vector<int> result;
        int len = S.length();
        //每个数组只有最有一个值被用到了，
        //可以被优化为一维数组
        vector<vector<int>> mat(26, vector<int>());
        for (int i = 0; i < len; ++i) {
            mat[S[i] - 'a'].push_back(i);
        }
        int max_idx = 0;
        int last = -1;
        for (int i = 0; i < len; ++i) {
            int char_offset = S[i] - 'a';
            int char_len = mat[char_offset].size();
            max_idx = max_idx > mat[char_offset][char_len - 1]
                          ? max_idx
                          : mat[char_offset][char_len - 1];
            if (i == max_idx) {
                result.push_back(max_idx - last);
                last = max_idx;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    sol.partitionLabels("ababcbacadefegdehijhklij");
}

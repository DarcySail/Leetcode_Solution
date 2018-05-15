#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    static unsigned int BKDRHash(char *str, int len)
    {
        unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;
        int i = 0;

        while (i++ < len) {
            hash = hash * seed + (*str++);
        }

        return (hash & 0x7FFFFFFF);
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        map<unsigned int, vector<string>> dict;
        // map<unsigned int, int> len_dict;

        for (int i = 0; i < strs.size(); ++i) {
            int arr[128] = {0};
            for (int j = 0; j < strs[i].length(); ++j) {
                arr[strs[i][j]]++;
            }
            unsigned int hash = BKDRHash((char *)arr, sizeof(arr));
            // if (len_dict.end() != len_dict.find(hash)) {
            //    if (len_dict[hash] != strs[i].length())
            //        ;
            //}
            //cout << hash << endl;
            dict[hash].push_back(strs[i]);
        }
        map<unsigned int, vector<string>>::iterator it = dict.begin();
        for (; it != dict.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};

int main()
{
    vector<string> con;
    con.push_back("eat");
    con.push_back("tea");
    con.push_back("tan");
    con.push_back("ate");
    con.push_back("nat");
    con.push_back("bat");

    Solution sol;

    vector<vector<string>> ans = sol.groupAnagrams(con);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

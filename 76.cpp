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
    string minWindow(string s, string t)
    {
        if (s.size() == 0 || t.size() == 0)
            return "";
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++)
            remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while (i <= s.size() && start < s.size()) {
            if (required) {
                if (i == s.size())
                    break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0)
                    required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0)
                    required++;
                start++;
            }
        }
        return min == INT_MAX ? "" : s.substr(left, min);
    }
};

int main()
{
    Solution sol;
    string _a = "ADOBECODEBANC";
    string a = "A";
    string b = "CAB";
    string c = "";
    string d = "ADF";
    string f = "ADOBECODEANC";
    string e = "ABC";
    cout << sol.minWindow(_a, e) << endl;
    // cout << sol.minWindow(a, e) << endl;
    // cout << sol.minWindow(b, e) << endl;
    // cout << sol.minWindow(c, e) << endl;
    // cout << sol.minWindow(d, e) << endl;
    // cout << sol.minWindow(e, e) << endl;
    cout << sol.minWindow(f, e) << endl;
}

// rubish 2
// class Solution
//{
//  public:
//    string minWindow(string s, string t)
//    {
//        if (s.length() == 0 || t.length() == 0)
//            return "";
//        int left, right;
//        int i = 0, j = 0;
//        map<char, int> freq_s, freq_t;
//        map<char, int>::iterator it_s, it_t;
//        vector<char> filter;
//        vector<char> idx_for_filter;
//        for (i = 0; i < t.length(); ++i) {
//            freq_t[t[i]]++;
//        }
//        for (i = 0; i < s.length(); ++i) {
//            if (freq_t.find(s[i]) != freq_t.end()) {
//                freq_s[s[i]]++;
//                filter.push_back(s[i]);
//                idx_for_filter.push_back(i);
//            }
//        }
//
//        it_t = freq_t.begin();
//        it_s = freq_s.begin();
//        for (; it_t != freq_t.end(); ++it_t) {
//            if (freq_s.find(it_t->first) == freq_s.end()) {
//                return "";
//            }
//            if (it_t->second > freq_s[it_t->first]) {
//                return "";
//            }
//        }
//
//        // handle first element
//        map<char, int> delta_dict(freq_t);
//        for (i = 0; i < filter.size() && delta_dict.size(); ++i) {
//            if (delta_dict.find(filter[i]) != delta_dict.end()) {
//                delta_dict[filter[i]]--;
//                if (delta_dict[filter[i]] == 0) {
//                    delta_dict.erase(filter[i]);
//                }
//            }
//        }
//        vector<int> dp(filter.size(), INT_MAX);
//        dp[0] = i - 1;
//
//        for (j = 0; j < i; ++j) {
//            delta_dict[filter[j]]++;
//        }
//        it_t = delta_dict.begin();
//        for (; it_t != delta_dict.end();) {
//            delta_dict[it_t->first] -= freq_t[it_t->first];
//            if (delta_dict[it_t->first] == 0) {
//                delta_dict.erase(it_t++);
//            } else {
//                ++it_t;
//            }
//        }
//
//        // handle other element
//        for (i = 1; i < filter.size(); ++i) {
//            delta_dict[filter[i - 1]]--;
//            if (delta_dict[filter[i - 1]] >= 0) {
//                dp[i] = dp[i - 1];
//            } else {
//                for (j = dp[i - 1] + 1; j < filter.size(); ++j) {
//                    delta_dict[filter[j]]++;
//                    if (delta_dict[filter[i - 1]] == 0) {
//                        dp[i] = j;
//                        break;
//                    }
//                }
//            }
//        }
//
//        // find min subset
//        int min_gap = INT_MAX;
//        for (i = 0; i < dp.size(); ++i) {
//            if (dp[i] == INT_MAX) {
//                break;
//            }
//            int gap = idx_for_filter[dp[i]] - idx_for_filter[i];
//            if (min_gap > gap) {
//                min_gap = gap;
//                left = idx_for_filter[i];
//                right = idx_for_filter[dp[i]];
//            }
//        }
//        return s.substr(left, right - left + 1);
//    }
//};

//
// rubish 1
// class Solution
//{
//  public:
//    string minWindow(string s, string t)
//    {
//        if (s.length() == 0 || t.length() == 0)
//            return "";
//        int left, right;
//        map<char, int> freq_s, freq_t;
//        map<char, int>::iterator it_s, it_t;
//        vector<char> filter;
//        vector<char> idx_for_filter;
//        for (int i = 0; i < t.length(); ++i) {
//            freq_t[t[i]]++;
//        }
//        for (int i = 0; i < s.length(); ++i) {
//            if (freq_t.find(s[i]) != freq_t.end()) {
//                freq_s[s[i]]++;
//                filter.push_back(s[i]);
//                idx_for_filter.push_back(i);
//            }
//        }
//
//        it_t = freq_t.begin();
//        it_s = freq_s.begin();
//        for (; it_t != freq_t.end(); ++it_t) {
//            if (freq_s.find(it_t->first) == freq_s.end()) {
//                return "";
//            }
//            if (it_t->second > freq_s[it_t->first]) {
//                return "";
//            }
//        }
//
//        bool flag = true;
//        left = 0, right = filter.size() - 1;
//        while (flag) {
//            int left_gap = idx_for_filter[left + 1] - idx_for_filter[left];
//            int right_gap = idx_for_filter[right] - idx_for_filter[right - 1];
//            cout << "left: " << left_gap << ", right: " << right_gap << endl;
//            if (left_gap > right_gap) {
//                if (freq_s[filter[left]] > freq_t[filter[left]]) {
//                    freq_s[filter[left]]--;
//                    left++;
//                } else if (freq_s[filter[right]] > freq_t[filter[right]]) {
//                    freq_s[filter[right]]--;
//                    right--;
//                } else {
//                    flag = false;
//                }
//            } else {
//                if (freq_s[filter[right]] > freq_t[filter[right]]) {
//                    freq_s[filter[right]]--;
//                    right--;
//                } else if (freq_s[filter[left]] > freq_t[filter[left]]) {
//                    freq_s[filter[left]]--;
//                    left++;
//                } else {
//                    flag = false;
//                }
//            }
//        }
//
//        return s.substr(idx_for_filter[left],
//                        idx_for_filter[right] - idx_for_filter[left] + 1);
//    }
//};
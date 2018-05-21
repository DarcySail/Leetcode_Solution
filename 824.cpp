#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    string toGoatLatin(string S)
    {
        if (S.length() == 0) {
            return S;
        }
        string result;
        map<char, bool> dict;
        dict['a'] = true;
        dict['e'] = true;
        dict['i'] = true;
        dict['o'] = true;
        dict['u'] = true;
        dict['A'] = true;
        dict['E'] = true;
        dict['I'] = true;
        dict['O'] = true;
        dict['U'] = true;

        int start = 0, end = 0, word_count = 1;
        while (end < S.length() && S[end] != ' ')
            ++end;
        string single_word = S.substr(start, end - start);
        if (dict.find((single_word[0])) == dict.end()) {
            single_word += single_word[0];
            single_word.erase(0, 1);
        }
        single_word += "ma";
        single_word += string(word_count, 'a');
        result = single_word;
        ++word_count;
        start = ++end;

        for (; end < S.length(); ) {
            while (end < S.length() && S[end] != ' ')
                ++end;
            single_word = S.substr(start, end - start);
            if (dict.find((single_word[0])) == dict.end()) {
                single_word += single_word[0];
                single_word.erase(0, 1);
            }
            single_word += "ma";
            single_word += string(word_count, 'a');
            single_word = ' ' + single_word;
            result += single_word;
            ++word_count;
            start = ++end;
        }

        return result;
    }
};

int main()
{
    Solution sol;

    cout << sol.toGoatLatin("I speak Goat Latin") << endl;
    cout << sol.toGoatLatin("The quick brown fox jumped over the lazy dog")
         << endl;
    cout << sol.toGoatLatin("HZ sg L") << endl;
}

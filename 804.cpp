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
    int uniqueMorseRepresentations(vector<string> &words)
    {
        map<string, bool> result;
        for (int i = 0; i < words.size(); ++i) {
            string code;
            for (int j = 0; j < words[i].length(); ++j) {
                code += str_arr[words[i][j] - 'a'];
            }
            result[code] = true;
        }
        return result.size();
    }
};

int main() { Solution sol; }

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

//一般而言，设P是[1,n]的一个全排列。
//　　　　　　P=P1P2…Pn=P1P2…Pj-1PjPj+1…Pk-1PkPk+1…Pn
//　　　　find:　　j=max{i|Pi<Pi+1}
//　　　　　　　　　k=max{i|Pi>Pj}
//　　　　　　1，  对换Pj，Pk，
//　　　　　　2，  将Pj+1…Pk-1PjPk+1…Pn翻转
//          P’= P1P2…Pj-1PkPn…Pk+1PjPk-1…Pj+1即P的下一个
class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        string base;
        for (int i = 1; i <= n; ++i) {
            base += '0' + i;
        }

        for (int i = 1; i < k; ++i) {
            int j = n - 2;
            for (; j >= 0 && base[j + 1] < base[j]; --j) {
            }
            if (j == -1)
                break; //不存在
            int m = n - 1;
            for (; m > j && base[m] < base[j]; --m) {
            }
            if (m == n)
                ; //不存在
            swap(base[j], base[m]);
            reverse(base.begin() + j + 1, base.end());
        }

        return base;
    }
};

int main()
{
    Solution sol;
    cout << sol.getPermutation(3, 3) << endl;
}

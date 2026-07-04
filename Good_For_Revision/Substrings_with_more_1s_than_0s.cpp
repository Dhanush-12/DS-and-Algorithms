#include<bits/stdc++.h>
using namespace std;

/*

    Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.

    Examples:

    Input: s = "011"
    Output: 4
    Explanation: There are 4 substring which has more 1s than 0s. i.e "011","1","11" and "1"

*/
class Solution {
    class Fenwick {
        vector<int> bit;
        int n;

        public:
        Fenwick(int n)
        {
            this->n = n;
            bit.assign(n+1, 0);
        }
        void add (int ind, int val)
        {
            while(ind <= n)
            {
                bit[ind] += val;
                ind += ind & -ind;
            }
        }
        int sum(int ind)
        {
            int res = 0;
            while(ind > 0)
            {
                res += bit[ind];
                ind -= ind & -ind;
            }
            return res;
        }
    };
  public:
    int countSubstring(string& s) {
        int n = (int)s.size();
        Fenwick fw(2*n + 5);
        int offset = n+2;
        int pref = 0;
        long long ans = 0;
        fw.add(pref+offset, 1);
        for(char ch : s) {
            if(ch == '1') pref++;
            else pref--;

            ans += fw.sum(pref+offset-1);

            fw.add(pref+offset, 1);
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.countSubstring(str)<<endl;
}

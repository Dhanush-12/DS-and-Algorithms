#include<bits/stdc++.h>
using namespace std;
/*
    Given two numbers as strings s1 and s2. Calculate their Product. Note: The numbers can
    be negative and You are not allowed to use any built-in function or convert the strings
    to integers. There can be zeros in the begining of the numbers. You don't need to specify
    '+' sign in the begining of positive numbers.

    Examples:

    Input: s1 = "0033", s2 = "2"
    Output: "66"
    Explanation: 33 * 2 = 66

    Input: s1 = "11", s2 = "23"
    Output: "253"
    Explanation: 11 * 23  = 253
    
    Input: s1 = "123", s2 = "0"
    Output: "0"
    Explanation: Anything multiplied by 0 is equal to 0.
*/
class Solution {
  public:
    string multiplyStrings(string &s1, string &s2) {
        int n = (int)s1.size();
        int m = (int)s2.size();
        int nEnd = 0;
        int mEnd = 0;
        while(nEnd < n && (s1[nEnd] == '-' || s1[nEnd] == '0')) nEnd++;
        while(mEnd < m && (s2[mEnd] == '-' || s2[mEnd] == '0')) mEnd++;
        if(nEnd == n || mEnd == m) return "0";

        vector<int> ans(n+m);

        for(int i=n-1;i>=nEnd;i--)
        {
            for(int j=m-1;j>=mEnd;j--)
            {
                int first = s1[i]-'0';
                int second = s2[j]-'0';

                int curr = first*second;
                int currValueInd = i+j+1;
                int carryInd = i+j;

                int total = curr+ans[currValueInd];
                ans[currValueInd] = total %10;
                ans[carryInd] += total/10;
            }
        }

        string res = "";
        bool ok = 0;
        for(char ch : ans)
        {
            if(ch == 0)
            {
                if(ok) res += char(ch+'0');
                continue;
            }
            res += char(ch+'0');
            ok = true;
        }

        if(s1[0] == '-' || s2[0] == '-')
        {
            if(s1[0] != '-' || s2[0] != '-') res = '-'+res;
        }

        if(res.size() == 1 && res[0] == '-') return "0";

        return res.size() == 1 ? "0" : res;
    }
};
int main()
{
    string a,b;
    cin>>a>>b;
    Solution s;
    cout<<s.multiplyStrings(a, b)<<endl;
}
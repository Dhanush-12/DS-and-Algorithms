#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given a string s, you have to find the number of palindromic subsequences
    (need not necessarily be distinct) present in the string s. 

    Examples:

    Input: s = "abcd"
    Output: 4
    Explanation: palindromic subsequence are : 'a' ,'b', 'c' ,'d'
    Input: s = "aab"
    Output: 4
    Explanation: palindromic subsequence are : 'a', 'a', 'b', 'aa'
    Input: s = "b"
    Output: 1
    Explanation: palindromic subsequence are : 'b'
*/
class Solution {
  public:
    // Using Bitmasks
    // Time Complexity: O(2^n)
    int countPS(string &s) {
        int n = (int)s.size();
        int cnt = 0;
        int maxi = (1 << n);
        for(int i=1;i<maxi;i++)
        {
            string ans = "";
            bool ok = true;
            int sz = 0;
            int total = __builtin_popcount(i);
            for(int ind = 0;ind < n; ind++)
            {
                if((1 << ind) & i)
                {
                    ans += s[ind];
                    sz++;
                    if(total-sz < sz && ans[sz-1] != ans[total-sz])
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) cnt++;
        }
        return cnt;
    }
    // Using Dynamic Programming
    // Time Complexity: O(n^2)
    int countPSTabulation(string &s)
    {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j = i+len-1;
                int val = dp[i+1][j]+dp[i][j-1];
                if(s[i] == s[j]) val += 1;
                else val -= dp[i+1][j-1];
                dp[i][j] = val;
            }
        }
        return dp[0][n-1];
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.countPSTabulation(str)<<endl;
}
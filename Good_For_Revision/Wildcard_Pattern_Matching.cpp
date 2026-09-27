#include<bits/stdc++.h>
using namespace std;
/*
    Problem : Given two strings pat and txt which may be of different sizes, You have to
    return true if the wildcard pattern i.e. pat, matches with txt else return false.

    The wildcard pattern pat can include the characters '?' and '*'.

    '?' – matches any single character.
    '*' – matches any sequence of characters (including the empty sequence).
    Note: The matching should cover the entire txt (not partial txt).

    Input: txt = "abcde", pat = "a?c*"
    Output: true
    Explanation: '?' matches with 'b' and '*' matches with "de".

    Input: txt = "baaabab", pat = "a*ab"
    Output: false
    Explanation: The pattern starts with a, but the text starts with b, so the pattern does
    not match the text.

    Input: txt = "abc", pat = "*"
    Output: true
    Explanation: '*' matches with whole text "abc".
*/
class Solution {
    bool solveRecursion(int i, int j, int n, int m, string &s, string &p)
    {
        if(i == n && j == m) return true;
        if(j == m) return false;

        if(i == n)
        {
            while(j < m)
            {
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }

        if(s[i] == p[j] || (p[j] == '?')) {
            return solveRecursion(i+1, j+1, n, m, s, p);
        }

        if(p[j] == '*') {
            bool take = solveRecursion(i+1, j, n, m, s, p);
            bool skip = solveRecursion(i, j+1, n, m, s, p);

            return (take || skip);
        }

        return false;
    }
    bool solveMemo(int i, int j, int n, int m, string &s, string &p, vector<vector<int>> &dp)
    {
        if(i == n && j == m) return true;
        if(j == m) return false;
        
        if(i == n)
        {
            while(j < m)
            {
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solveMemo(i+1, j+1, n, m, s, p, dp);
        }
        
        if(p[j] == '*') {
            bool take = solveMemo(i+1, j, n, m, s, p, dp);
            bool skip = solveMemo(i, j+1, n, m, s, p, dp);
            
            return dp[i][j] = (take || skip);
        }
        
        return dp[i][j] = false;
    }
  public:
    bool wildCard(string &txt, string &pat) {
        int n = (int)txt.size();
        int m = (int)pat.size();

        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        // return solveMemo(0, 0, n, m, txt, pat, dp);

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        dp[n][m] = 1;
        for(int i=m-1;i>=0;i--)
        {
            if(pat[i] == '*') dp[n][i] = 1;
            else break;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(txt[i] == pat[j] || (pat[j] == '?')) dp[i][j] = dp[i+1][j+1];
                else if(pat[j] == '*')
                {
                    bool take = dp[i+1][j];
                    bool skip = dp[i][j+1];
                    dp[i][j] = (take | skip);
                }
                else dp[i][j] = 0;
            }
        }
        return dp[0][0];
    }
};
int main()
{
    string s,t;
    cin>>s>>t;
    Solution obj;
    cout<<obj.wildCard(s, t)<<endl;
}
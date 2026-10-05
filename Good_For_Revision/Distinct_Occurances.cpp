#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    You are given two strings txt and pat, find the count of distinct occurrences of pat as a
    subsequence in txt.

    Note: It is guaranteed that the ans will fit within a 32-bit integer.

    Input: txt = "abba", pat = "aba"
    Output: 2

    Input: txt = "banana", pat = "ban"
    Output: 3
*/
class Solution {
    int solve(int i, int j, int n, int m, string &txt, string &pat, vector<vector<int>> &dp)
    {
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0, not_take = 0;

        if(txt[i] == pat[j])
        {
            take = solve(i+1, j+1, n, m, txt, pat, dp);
        }
        not_take = solve(i+1, j, n, m, txt, pat, dp);
        return dp[i][j] = take+not_take;
    }
  public:
    int subseqCount(string &txt, string &pat) {
        int n = (int)txt.size();
        int m = (int)pat.size();

        //vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //return solve(0, 0, n, m, txt, pat, dp);

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=0;i<=n;i++) dp[i][m] = 1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int take = 0, not_take = 0;
                if(txt[i] == pat[j])
                {
                    take = dp[i+1][j+1];
                }
                not_take = dp[i+1][j];
                dp[i][j] = take+not_take;
            }
        }

        return dp[0][0];
    }
};
int main() 
{
    string txt, pat;
    cin>>txt>>pat;
    Solution s;
    cout<<s.subseqCount(txt, pat)<<endl;
}
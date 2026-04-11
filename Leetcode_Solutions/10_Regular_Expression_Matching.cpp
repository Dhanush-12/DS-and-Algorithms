#include<bits/stdc++.h>
using namespace std;
class Solution {
    // Time Complexity : Exponential
    // Space Complexity: O(1)
    bool solveRecursive(int i, int j, string &s, string &p)
    {
        if(j == p.size()) return i == s.size();

        bool match = (i < s.size() && s[i] == p[j] || p[j] == '.');

        if(j+1 < p.size() && p[j+1] == '*')
        {
            return solveRecursive(i, j+2, s, p) || (match && solveRecursive(i+1, j, s, p));
        }

        return match && solveRecursive(i+1, j+1, s, p);
    }
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)
    bool solveMemoized(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        if(j == p.size()) return i == s.size();

        if(dp[i][j] != -1) return dp[i][j];

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < p.size() && p[j+1] == '*')
        {
            return solveMemoized(i, j+2, s, p, dp) || (match && solveMemoized(i+1, j, s, p, dp));
        }

        return dp[i][j] = match && solveMemoized(i+1, j+1, s, p, dp);
    }
public:
    bool isMatchRecursion(string s, string p) {
        return solveRecursive(0,0,s,p);
    }
    bool isMatchMemoize(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveMemoized(0, 0, s, p, dp);
    }
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)
    bool isMatchTabulation(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n][m] = 1;
        for(int j = m-1; j >= 0; j--)
        {
            if(j+1 < m && p[j+1] == '*')
                dp[n][j] = dp[n][j+2];
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
                if(j+1 < m && p[j+1] == '*')
                {
                    dp[i][j] = dp[i][j+2] || (match && dp[i+1][j]);
                }
                else dp[i][j] = (match && dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    string s,p;
    cin>>s>>p;
    Solution sl;
    cout<<sl.isMatchTabulation(s,p)<<endl;
}

#include<bits/stdc++.h>
using namespace std;

/*
    Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.
    Return the total count modulo 1e9+7.

    Input: s1 = "geeksforgeeks", s2 = "gks"
    Output: 4
*/

class Solution {
    const int inf = (int)(1e9) + 7;
    // Recursion and memo
    // Time Complexity: O(n*m)
    // Space Complecity: O(n*m)
    int solve(int i, int j, int n, int m, string &s, string &p, vector<vector<int>>&dp)
    {
        if(i == n && j < m) return 0;
        if(j == m) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j])
        {
            return dp[i][j] = (solve(i+1, j+1, n, m, s, p, dp) + solve(i+1, j, n, m, s, p, dp)) % inf;
        }

        return dp[i][j] = solve(i+1, j, n, m, s, p, dp);

    }
  public:
    int countWays(string &s1, string &s2) {
        int n = (int)s1.size();
        int m = (int)s2.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //return solve(0, 0, n, m, s1, s2, dp);

        // Tabulation
        // Time Complexity: O(n*m)
        // Space Complexity: O(n*m)
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++) dp[i][m] = 1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = (dp[i+1][j+1]+dp[i+1][j]) % inf;
                }
                else dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.countWays(s1, s2)<<endl;
}

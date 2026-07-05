#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;

/*

    Problem: You are given two strings s and t consisting of lowercase English letters. You may choose at most one index in s and
    replace the character at that index with any lowercase English letter. Return true if it is possible to make s a subsequence
    of t; otherwise, return false.

    Example 1:

    Input: s = "cat", t = "chat"

    Output: true

*/

class Solution {
public:
    // DP approach
    // Time Complexity: O(n*m*2)
    // Space Complexity: O(n*m*2)
    bool canMakeSubsequence(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        if(n > m) return false;
        //return solve(0, 0, 0, n, m, s, t);
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2, 0)));
        for(int i=0;i<=m;i++) dp[n][i][0] = dp[n][i][1] = 1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                for(int k=0;k<2;k++)
                {
                    if(s[i] == t[j])
                    {
                        dp[i][j][k] = dp[i+1][j+1][k];
                    }
                    else
                    {
                        if(k == 0) dp[i][j][k] = (dp[i+1][j+1][1] || dp[i][j+1][k]);
                        else dp[i][j][k] = dp[i][j+1][k];
                    }
                }
            }
        }
        return dp[0][0][0];
    }
    // Most Optimal approach
    // Time Complexity : O(m);
    // Space Complexity : O(1)
    bool canMakeSubsequence(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        if(n > m) return false;
        int noReplace = 0, usedReplace = 0;
        for(char ch : t)
        {
            int newNoReplace = noReplace;
            int newUsedReplace = usedReplace;

            if(usedReplace < n && s[usedReplace] == ch)
            {
                newUsedReplace = max(newUsedReplace, usedReplace+1);
            }

            if(noReplace < n)
            {
                newUsedReplace = max(newUsedReplace, noReplace+1);
            }

            if(noReplace < n && s[noReplace] == ch)
            {
                newNoReplace = noReplace+1;
            }

            noReplace = newNoReplace;
            usedReplace = newUsedReplace;
        }
        return (noReplace == n || usedReplace == n);
    }
};
int main()
{
    string str, t;
    cin>>str>>t;
    Solution s;
    cout<<s.canMakeSubsequence(str, t)<<endl;
}

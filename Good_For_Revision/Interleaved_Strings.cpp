#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1
    and s2.

    Interleaving of two strings s1 and s2 is a way to mix their characters to form a new string
    s3, while maintaining the relative order of characters from s1 and s2. Conditions for
    interleaving:

    Characters from s1 must appear in the same order in s3 as they are in s1.
    Characters from s2 must appear in the same order in s3 as they are in s2.
    The length of s3 must be equal to the combined length of s1 and s2.

    Input: s1 = "AAB", s2 = "AAC", s3 = "AAAABC"
    Output: true
    Explanation: The string "AAAABC" has all characters of the other two strings and in the
    same order.

    Input: s1 = "AB", s2 = "C", s3 = "ACB"
    Output: true
    Explanation: s3 has all characters of s1 and s2 and retains order of characters of
    s1.

    Input: s1 = "YX", s2 = "X", s3 = "XXY"
    Output: false
    Explanation: "XXY " is not interleaved of "YX" and "X". The strings that can be formed are
    YXX and XYX
*/
class Solution {
    bool solve(int i, int j, int k, int n, int m, int l, string &s1, string &s2, string &s3,
                vector<vector<int>> &dp)
    {
        if(k == l) return (i == n && j == m);

        if(dp[i][j] != -1) return dp[i][j];

        if(i < n && j < m && k < l && s1[i] != s3[k] && s2[j] != s3[k]) return false;

        bool takeForS1 = false, takeForS2 = false;

        if((i < n && s1[i] == s3[k]) && (j < m && s2[j] == s3[k]))
        {
            takeForS1 = solve(i+1, j, k+1, n, m, l, s1, s2, s3, dp);
            takeForS2 = solve(i, j+1, k+1, n, m, l, s1, s2, s3, dp);
        }
        else if(i < n && s1[i] == s3[k])
        {
            takeForS1 = solve(i+1, j, k+1, n, m, l, s1, s2, s3, dp);
        }
        else if(j < m && s2[j] == s3[k])
        {
            takeForS2 = solve(i, j+1, k+1, n, m, l, s1, s2, s3, dp);
        }

        return dp[i][j] = (takeForS1 || takeForS2);
    }
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n = (int)s1.size();
        int m = (int)s2.size();
        int l = (int)s3.size();

        if(n+m != l) return false;

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        // return solve(0, 0, 0, n, m, l, s1, s2, s3, dp);

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        dp[n][m] = 1;

        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i == n && j == m) continue;

                int k = i+j;
                bool takeForS1 = false, takeForS2 = false;

                if(i < n && s1[i] == s3[k]) takeForS1 = dp[i+1][j];
                if(j < m && s2[j] == s3[k]) takeForS2 = dp[i][j+1];

                dp[i][j] = (takeForS1 || takeForS2);
            }
        }

        return dp[0][0];
    }
};
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    Solution s;
    cout<<s.isInterleave(s1, s2, s3)<<endl;
}
/*
DNYGLQH
NJOHGAP
DNYGLQNJOHGAPH

AAB
AAC
AAAABC

AB
C
ACB

YX
X
XXY
*/
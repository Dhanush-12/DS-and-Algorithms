#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Time complexity : O(2^n) and Space complexity : O(n+m)
int recursion(int ind1,int ind2,string s,string t)
{
    if(ind1<0 && ind2<0) return 1;
    if(ind1<0 && ind2>=0) return 0;
    if(ind1>=0 && ind2<0)
    {
        for(int i=0;i<=ind1;i++)
        {
            if(s[i]!='*') return 0;
        }
        return 1;
    }
    if(s[ind1]==t[ind2] || s[ind1]=='?') return recursion(ind1-1,ind2-1,s,t);
    if(s[ind1]=='*')
    {
        return recursion(ind1-1,ind2,s,t) | recursion(ind1,ind2-1,s,t);
    }
    return 0;
}
// Time complexity : O(n*m) and Space complexity : O(n*m)
int memorization(int ind1,int ind2,string s,string t,vector<vector<int>>&dp)
{
    if(ind1<0 && ind2<0) return 1;
    if(ind1<0 && ind2>=0) return 0;
    if(ind1>=0 && ind2<0)
    {
        for(int i=0;i<=ind1;i++)
        {
            if(s[i]!='*') return 0;
        }
        return 1;
    }
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s[ind1]==t[ind2] || s[ind1]=='?') return memorization(ind1-1,ind2-1,s,t,dp);
    if(s[ind1]=='*')
    {
        return dp[ind1][ind2] = (memorization(ind1-1,ind2,s,t,dp) | memorization(ind1,ind2-1,s,t,dp));
    }
    return dp[ind1][ind2] = 0;
}
// Time complexity : O(n*m) and Space complexity : O(n*m)
int tabulation(int n,int m,string s,string t,vector<vector<int>>&dp)
{
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int f=1;
        for(int j=1;j<=i;j++)
        {
            if(s[i-1]!='*')
            {
                f=0;
                break;
            }
        }
        dp[i][0]=f;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1] || s[i-1]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(s[i-1]=='*')
            {
                dp[i][j]=(dp[i-1][j] | dp[i][j-1]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return dp[n][m];
}
// Time Complexity : O(n*m) and Space complexity : O(m)
int space_optimization(int n,int m,string s,string t)
{
    vector<int>prev(m+1,0),curr(m+1,0);
    prev[0]=curr[0]=1;
    for(int i=1;i<=n;i++)
    {
        int f=1;
        for(int j=1;j<=i;j++)
        {
            if(s[j-1]!='*')
            {
                f=0;
                break;
            }
            curr[0]=f;
        }
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1] || s[i-1]=='?')
            {
                curr[j]=prev[j-1];
            }
            else if(s[i-1]=='*')
            {
                curr[j]=(prev[j] | curr[j-1]);
            }
            else
            {
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return prev[m];
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    cout<<"Answer using recursion: "<<recursion(n-1,m-1,s,t)<<endl;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,m-1,s,t,dp)<<endl;
    vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,s,t,dp1)<<endl;
    cout<<"Answer using Space optimization: "<<space_optimization(n,m,s,t)<<endl;
}

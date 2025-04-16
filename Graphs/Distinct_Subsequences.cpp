#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int recursion(int ind1,int ind2,string s,string t)
{
    if(ind2<0) return 1;
    if(ind1<0) return 0;

    if(s[ind1]==t[ind2])
    {
        return recursion(ind1-1,ind2-1,s,t)+recursion(ind1-1,ind2,s,t);
    }

    return recursion(ind1-1,ind2,s,t);
}
int memorization(int ind1,int ind2,string s,string t,vector<vector<int>>&dp)
{
    if(ind2<0) return 1;
    if(ind1<0) return 0;

    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s[ind1]==t[ind2])
    {
        return dp[ind1][ind2]=memorization(ind1-1,ind2-1,s,t,dp)+memorization(ind1-1,ind2,s,t,dp);
    }

    return memorization(ind1-1,ind2,s,t,dp);
}
int tabulation(int n,int m,string s,string t,vector<vector<int>>&dp)
{
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(s[0]==t[0]) dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
// Time complexity: O(n*m) and Space complexity: O(m)
int space_optimization(int n,int m,string s,string t)
{
    vector<int>prev(m+1,0),curr(m+1,0);
    prev[0]=curr[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                curr[j]=prev[j-1]+prev[j];
            }
            else
            {
                curr[j]=prev[j];
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

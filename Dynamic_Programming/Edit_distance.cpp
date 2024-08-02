#include<bits/stdc++.h>
using namespace std;
int recursion(int i,int j,string s,string t)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(s[i]==t[j]) return recursion(i-1,j-1,s,t);
    return 1+min({recursion(i-1,j,s,t),recursion(i,j-1,s,t),recursion(i-1,j-1,s,t)});
}
int memo(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return memo(i-1,j-1,s,t,dp);
    return dp[i][j]=1+min({memo(i-1,j,s,t,dp),memo(i,j-1,s,t,dp),memo(i-1,j-1,s,t,dp)});
}
int tabulation(int n,int m,string s,string t,vector<vector<int>>&dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}
int main()
{
    int n,m;
    string str,ptr;
    cin>>n>>m>>str>>ptr;
    cout<<"Using Recursion : ";
    int ans=recursion(n-1,m-1,str,ptr);
    cout<<ans<<endl;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    ans=memo(n-1,m-1,str,ptr,dp);
    cout<<"Using Memorization : ";
    cout<<ans<<endl;
    vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
    ans=tabulation(n,m,str,ptr,dp1);
    cout<<"Using Tabulation : ";
    cout<<ans<<endl;
}

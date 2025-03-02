#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
//
// Time Complexity: O(2^n) and Space Complexity: O(n+m);
int recursion(int ind1,int ind2,string s,string t,int ans)
{
    if(ind1<0 || ind2<0) return ans;
    if(s[ind1]==t[ind2]) return recursion(ind1-1,ind2-1,s,t,ans+1);
    ans=max(ans,max(recursion(ind1-1,ind2,s,t,0),recursion(ind1,ind2-1,s,t,0)));
    return ans;
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m);
int tabulation(int n,int m,string s,string t,vector<vector<int>>&dp)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
}
// Time Complexity: O(n*m) and Space Complexity: O(m);
int space_optimization(int n,int m,string s,string t)
{
    int ans=0;
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }
            else curr[j]=0;
        }
        prev=curr;
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int ans=0;
    cout<<"Answer using recursion: "<<recursion(n-1,m-1,s,t,ans)<<endl;
    vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,s,t,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,m,s,t)<<endl;
}

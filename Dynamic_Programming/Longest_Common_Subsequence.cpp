#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
//
// Time Complexity: O(2^n) and Space Complexity: O(n+m);
int recursion(int ind1,int ind2,string s,string t)
{
    if(ind1<0 || ind2<0) return 0;
    if(s[ind1]==t[ind2]) return 1+recursion(ind1-1,ind2-1,s,t);
    else return max(recursion(ind1-1,ind2,s,t),recursion(ind1,ind2-1,s,t));
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)+O(n+m);
int memorization(int ind1,int ind2,string s,string t,vector<vector<int>>&dp)
{
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s[ind1]==t[ind2]) return dp[ind1][ind2]=(1+memorization(ind1-1,ind2-1,s,t,dp));
    else return dp[ind1][ind2]=max(memorization(ind1-1,ind2,s,t,dp),memorization(ind1,ind2-1,s,t,dp));
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m);
int tabulation(int n,int m,string s,string t,vector<vector<int>>&dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
// Time Complexity: O(n*m) and Space Complexity: O(m);
int space_optimization(int n,int m,string s,string t)
{
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[m];
}
// Printing the LCS
string print_LCS(int n,int m,string s,string t,vector<vector<int>>&dp)
{
    string ans;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans+=t[j-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    cout<<"Answer using recursion: "<<recursion(n-1,m-1,s,t)<<endl;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<"Answer using memorization: "<<memorization(n-1,m-1,s,t,dp)<<endl;
    vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,s,t,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,m,s,t)<<endl;
    cout<<"Longest Common Subsequence is: "<<print_LCS(n,m,s,t,dp1)<<endl;
}

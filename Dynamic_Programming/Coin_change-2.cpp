#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
//  You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W,
//  in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.
// Time Complexity: O(2^n) and Space Complexity: O(n);
int recursion(int ind,vector<int>&arr,int t)
{
   if(ind==0)
   {
       if(t%arr[ind]==0) return 1;
       else return 0;
   }
   int not_take=recursion(ind-1,arr,t);
   int take=0;
   if(t>=arr[ind]) take=recursion(ind,arr,t-arr[ind]);
   return take+not_take;
}
// Time Complexity: O(n*t) and Space Complexity: O(n*t)+O(n);
int memorization(int ind,vector<int>&arr,int t,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(t%arr[ind]==0) return 1;
        else return 0;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int not_take=memorization(ind-1,arr,t,dp);
    int take=0;
    if(t>=arr[ind]) take=memorization(ind,arr,t-arr[ind],dp);
    return dp[ind][t]=(take+not_take);
}
// Time Complexity: O(n*t) and Space Complexity: O(n*t);
int tabulation(int n,vector<int>&arr,int t,vector<vector<int>>&dp)
{
    for(int i=0;i<=t;i++)
    {
        if(i%arr[0]==0) dp[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(j>=arr[i]) take=dp[i][j-arr[i]];
            dp[i][j]=(take+not_take);
        }
    }
    return dp[n-1][t];
}
// Time Complexity: O(n*t) and Space Complexity: O(t);
int space_optimization(int n,vector<int>&arr,int t)
{
    vector<int>prev(t+1,0),curr(t+1,0);
    for(int i=0;i<=t;i++)
    {
        if(i%arr[0]==0) prev[i]=1;
    }
    curr=prev;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            int not_take=prev[j];
            int take=0;
            if(j>=arr[i]) take=curr[j-arr[i]];
            curr[j]=(take+not_take);
        }
        prev=curr;
    }
    return prev[t];
}
int main()
{
    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the Recursion: "<<recursion(n-1,arr,t)<<endl;
    vector<vector<int>>dp(n,vector<int>(t+1,-1));
    cout<<"Answer using the Memorization: "<<memorization(n-1,arr,t,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(t+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,arr,t,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,arr,t)<<endl;
}

#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// We are given a target sum and an array contains the integer values denoting the values of the respective coins. We need to find the minimum number of coins needed
// that the values of the coins sum up the target value.
// Time Complexity: O(2^n) and Space Complexity: O(n);
int recursion(int ind,vector<int>&arr,int t)
{
   if(ind==0)
   {
       if(t%arr[0]==0) return t/arr[0];
       else return inf;
   }
   int not_take=recursion(ind-1,arr,t);
   int take=inf;
   if(t>=arr[ind]) take=1+recursion(ind,arr,t-arr[ind]);

   return min(take,not_take);
}
// Time Complexity: O(n*t) and Space Complexity: O(n*t)+O(n);
int memorization(int ind,vector<int>&arr,int t,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(t%arr[0]==0) return t/arr[0];
        return inf;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int not_take=memorization(ind-1,arr,t,dp);
    int take=inf;
    if(t>=arr[ind]) take=1+memorization(ind,arr,t-arr[ind],dp);

    return dp[ind][t]=min(take,not_take);
}
// Time Complexity: O(n*t) and Space Complexity: O(n*t);
int tabulation(int n,vector<int>&arr,int t,vector<vector<int>>&dp)
{
    for(int i=0;i<=t;i++)
    {
        if(i%arr[0]==0) dp[0][i]=(i/arr[0]);
        else dp[0][i]=inf;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
             int not_take=dp[i-1][j];
             int take=inf;
             if(j>=arr[i]) take=1+dp[i][j-arr[i]];
             dp[i][j]=min(take,not_take);
        }
    }
    if(dp[n-1][t]>=inf) return -1;
    return dp[n-1][t];
}
// Time Complexity: O(n*t) and Space Complexity: O(t);
int space_optimization(int n,vector<int>&arr,int t)
{
    vector<int>prev(t+1,0),curr(t+1,0);
    for(int i=0;i<=t;i++)
    {
        if(i%arr[0]==0) prev[i]=(i/arr[0]);
        else prev[i]=inf;
    }
    curr=prev;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            int not_take=prev[j];
            int take=inf;
            if(j>=arr[i]) take=1+curr[j-arr[i]];
            curr[j]=min(take,not_take);
        }
        prev=curr;
    }
    if(prev[t]==inf) return -1;
    return prev[t];
}
int main()
{
    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=recursion(n-1,arr,t);
    if(ans==inf) ans=-1;
    cout<<"Answer using the Recursion: "<<ans<<endl;
    vector<vector<int>>dp(n,vector<int>(t+1,-1));
    ans=memorization(n-1,arr,t,dp);
    if(ans==inf) ans=-1;
    cout<<"Answer using Memorization: "<<ans<<endl;
    vector<vector<int>>dp1(n,vector<int>(t+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,arr,t,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,arr,t)<<endl;
}

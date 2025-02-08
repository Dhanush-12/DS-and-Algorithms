#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// We are given an array and a target, we have to find the number of subsets we can form whose individual sums equal to target.
// Time Complexity: O(2^n) and Space Complexity: O(n);
int recursion(int ind,int t,vector<int>&arr)
{
   if(t==0) return 1;
   if(ind==0)
   {
       if(arr[0]==t) return 1;
       else return 0;
   }
   int not_take=recursion(ind-1,t,arr);
   int take=0;
   if(t>=arr[ind]) take=recursion(ind-1,t-arr[ind],arr);
   return (take+not_take);
}
// Time Complexity: O(n*target) and Space Complexity: O(n*target)+O(n);
int memorization(int ind,int t,vector<int>&arr,vector<vector<int>>&dp)
{
    if(t==0) return 1;
    if(ind==0)
    {
        if(arr[ind]==t) return 1;
        else return 0;
    }
    int not_take=memorization(ind-1,t,arr,dp);
    int take=0;
    if(t>=arr[ind]) take=memorization(ind-1,t-arr[ind],arr,dp);
    return dp[ind][t]=(take+not_take);
}
// Time Complexity: O(n*target) and Space Complexity: O(n*target);
int tabulation(int n,int t,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(t>=arr[0]) dp[0][arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(j>=arr[i]) take=dp[i-1][j-arr[i]];
            dp[i][j]=(take+not_take);
        }
    }
    return dp[n-1][t];
}
// Time Complexity: O(n*target) and Space Complexity: O(target);
int space_optimization(int n,int t,vector<int>&arr)
{
    vector<int>prev(t+1,0),curr(t+1,0);
    prev[0]=curr[0]=1;
    if(t>=arr[0]) prev[arr[0]]=curr[arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            int not_take=prev[j];
            int take=0;
            if(j>=arr[i]) take=prev[j-arr[i]];
            curr[j]=(take+not_take);
        }
        prev=curr;
    }
    return prev[t];
}
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the Recursion: "<<recursion(n-1,target,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,target,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(target+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,target,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,target,arr)<<endl;
}

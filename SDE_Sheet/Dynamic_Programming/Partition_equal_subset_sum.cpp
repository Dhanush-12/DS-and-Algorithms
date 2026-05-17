#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Given an array of size n. We are asked to partition the array into two non empty subsets, whose sum of the elements in one subset are equal to another.
// Time Complexity: O(2^n) and Space Complexity: O(n);
bool recursion(int ind,int t,vector<int>&arr)
{
   if(t==0) return true;
   if(ind==0) return (t==arr[0]);
   bool not_take=recursion(ind-1,t,arr);
   bool take=false;
   if(t>=arr[ind]) take=recursion(ind-1,t-arr[ind],arr);

   return take|not_take;
}
// Time Complexity: O(n*target) and Space Complexity: O(n*target)+O(n);
bool memorization(int ind,int t,vector<int>&arr,vector<vector<int>>&dp)
{
    if(t==0) return true;
    if(ind==0) return (t==arr[0]);
    if(dp[ind][t]!=-1) return dp[ind][t];
    bool not_take=memorization(ind-1,t,arr,dp);
    bool take=false;
    if(t>=arr[ind]) take=memorization(ind-1,t-arr[ind],arr,dp);
    return dp[ind][t]=(take|not_take);
}
// Time Complexity: O(n*target) and Space Complexity: O(n*target);
bool tabulation(int n,int t,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    if(arr[0]<=t) dp[0][arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            bool not_take=dp[i-1][j];
            bool take=false;
            if(j>=arr[i]) take=dp[i-1][j-arr[i]];
            dp[i][j]=(take|not_take);
        }
    }
    return dp[n-1][t];
}
// Time Complexity: O(n*target) and Space Complexity: O(target);
bool space_optimization(int n,int t,vector<int>&arr)
{
    vector<bool>prev(t+1,0);
    vector<bool>curr(t+1,0);
    prev[0]=curr[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            bool not_take=prev[j];
            bool take=false;
            if(j>=arr[i]) take=prev[j-arr[i]];
            curr[j]=(take|not_take);
        }
        prev=curr;
    }
    return prev[t];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int target=accumulate(arr.begin(),arr.end(),0);
    if(target&1)
    {
        cout<<"Not Possible"<<endl;
        return 0;
    }
    target/=2;
    cout<<"Answer using the Recursion: "<<recursion(n-1,target,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,target,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(target+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,target,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,target,arr)<<endl;
}

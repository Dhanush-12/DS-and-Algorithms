#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
//  Given an array of integers and also given an a target integer. We are supposed to assign the + or - signs of each of the element in the array. So that the total
// arithematic sum of the array elements is equal to target. Find the number of such arrangements of the (+ and -) signs to achieve the sum = target.
// Time Complexity: O(2^n) and Space Complexity: O(n);
int recursion(int ind,vector<int>&arr,int t)
{
   if(arr[0]==0 && t==0) return 2;
   if(ind==0)
   {
       if(arr[0]==t || t==0) return 1;
       else return 0;
   }
   int not_take=recursion(ind-1,arr,t);
   int take=0;
   if(arr[ind]<=t) take=recursion(ind-1,arr,t-arr[ind]);
   return take+not_take;
}
// Time Complexity: O(n*t) and Space Complexity: O(n*t)+O(n);
int memorization(int ind,vector<int>&arr,int t,vector<vector<int>>&dp)
{
    if(arr[0]==0 && t==0) return 2;
    if(ind==0)
    {
        if(arr[0]==t || t==0) return 1;
        else return 0;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int not_take=memorization(ind-1,arr,t,dp);
    int take=0;
    if(t>=arr[ind]) take=memorization(ind-1,arr,t-arr[ind],dp);
    return dp[ind][t]=(take+not_take);
}
// Time Complexity: O(n*t) and Space Complexity: O(n*t);
int tabulation(int n,vector<int>&arr,int t,vector<vector<int>>&dp)
{
    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0 && t>=arr[0]) dp[0][arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(j>=arr[i]) take=dp[i-1][j-arr[i]];
            dp[i][j]=(take+not_take);
        }
    }
    return dp[n-1][t];
}
// Time Complexity: O(n*t) and Space Complexity: O(t);
int space_optimization(int n,vector<int>&arr,int t)
{
    vector<int>prev(t+1,0),curr(t+1,0);
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    if(arr[0]!=0 && t>=arr[0]) prev[arr[0]]=1;
    curr=prev;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
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
    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=accumulate(arr.begin(),arr.end(),0);
    int req=(t+sum);
    if(req&1)
    {
        cout<<"Not possible"<<endl;
        return 0;
    }
    req=req/2;
    cout<<"Answer using the Recursion: "<<recursion(n-1,arr,req)<<endl;
    vector<vector<int>>dp(n,vector<int>(req+1,-1));
    cout<<"Answer using the Memorization: "<<memorization(n-1,arr,req,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(req+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,arr,req,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,arr,req)<<endl;
}

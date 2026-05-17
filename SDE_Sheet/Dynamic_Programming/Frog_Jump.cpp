#include<bits/stdc++.h>
using namespace std;
// A frog has to reach the nth step from the current, it can only jump to i+1 or i+2th step front current ith step, the cost of jumping from i to i+1th step is abs(arr[i+1]-arr[i]).
// Return the minimum cost to reach the nth step from initial step.

// Time complexity: O(2^n) and Space Complexity: O(n)
int recursion(int ind,vector<int>&arr)
{
    if(ind==0) return 0;
    int left=abs(arr[ind]-arr[ind-1])+recursion(ind-1,arr);
    int right=INT_MAX;
    if(ind>1) right=abs(arr[ind]-arr[ind-2])+recursion(ind-2,arr);
    return min(left,right);
}
// Time complexity: O(n) and Space Complexity: O(n)
int memorization(int ind,vector<int>&dp,vector<int>&arr)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=abs(arr[ind]-arr[ind-1])+memorization(ind-1,dp,arr);
    int right=INT_MAX;
    if(ind>1) right=abs(arr[ind]-arr[ind-2])+memorization(ind-2,dp,arr);
    return dp[ind]=min(left,right);
}
// Time complexity: O(n) and Space Complexity: O(n)
int tabulation(int n,vector<int>&dp,vector<int>&arr)
{
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int left=abs(arr[i]-arr[i-1])+dp[i-1];
        int right=INT_MAX;
        if(i>1) right=abs(arr[i]-arr[i-2])+dp[i-2];
        dp[i]=min(left,right);
    }
    return dp[n-1];
}
// Time complexity: O(n) and Space Complexity: O(1)
int spaceOptimization(int n,vector<int>&arr)
{
    int prev=0,curr=0;
    for(int i=1;i<n;i++)
    {
        int left=abs(arr[i]-arr[i-1])+curr;
        int right=INT_MAX;
        if(i>1) right=abs(arr[i]-arr[i-2])+prev;
        prev=curr;
        curr=min(left,right);
    }
    return curr;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using recursion: "<<recursion(n-1,arr)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Answer using memorization: "<<memorization(n-1,dp,arr)<<endl;
    vector<int>dp1(n,0);
    cout<<"Answer using tabulation: "<<tabulation(n,dp1,arr)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,arr)<<endl;
}

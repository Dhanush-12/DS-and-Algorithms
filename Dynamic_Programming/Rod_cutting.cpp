#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
//  Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by 
//cutting the rod and selling its pieces.
// Time Complexity: O(2^n) and Space Complexity: O(n);
int recursion(int ind,int t,vector<int>&arr)
{
    if(ind==0)
    {
        return t*arr[0];
    }
    int not_take=recursion(ind-1,t,arr);
    int take=INT_MIN;
    if(t>=(ind+1)) take=arr[ind]+recursion(ind,t-(ind+1),arr);
    return max(take,not_take);
}
// Time Complexity: O(n*n) and Space Complexity: O(n*n)+O(n);
int memorization(int ind,int t,vector<int>&arr,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        return t*arr[0];
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int not_take=memorization(ind-1,t,arr,dp);
    int take=INT_MIN;
    if(t>=(ind+1)) take=arr[ind]+memorization(ind,t-(ind+1),arr,dp);
    return dp[ind][t]=max(take,not_take);
}
// Time Complexity: O(n*n) and Space Complexity: O(n*n);
int tabulation(int n,int t,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=0;i<=t;i++)
    {
        dp[0][i]=i*arr[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(j>=(i+1)) take=arr[i]+dp[i][j-(i+1)];
            dp[i][j]=max(take,not_take);
        }
    }
    return dp[n-1][t];
}
// Time Complexity: O(n*n) and Space Complexity: O(n);
int space_optimization(int n,int t,vector<int>&arr)
{
    vector<int>prev(t+1,0),curr(t+1,0);
    for(int i=0;i<=t;i++)
    {
        prev[i]=i*arr[0];
    }
    curr=prev;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            int not_take=prev[j];
            int take=0;
            if(j>=(i+1)) take=arr[i]+curr[j-(i+1)];
            curr[j]=max(take,not_take);
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
    cout<<"Answer using the Recursion: "<<recursion(n-1,n,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,n,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(n+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,n,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,n,arr)<<endl;
}

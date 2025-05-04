#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// You are given an array of the prices of the stock on n days. You can perform multiple buy and a sell operation so that
// you will get the maximum profit. Note that you can only buy the stock if you have not bought it before and you can only sell the stock if you have bought it before.
// Time complexity: O(2^n) and Space complexity: O(n)
int recursion(int ind,int n,int value,vector<int>&arr)
{
    if(ind==n) return 0;
    int ans=0;

    if(value==-1)
    {
        ans=max(-arr[ind]+recursion(ind+1,n,arr[ind],arr), recursion(ind+1,n,-1,arr));
    }
    else
    {
        ans=max(arr[ind]+recursion(ind+1,n,-1,arr),recursion(ind+1,n,value,arr));
    }
    return ans;
}
// Time complexity: O(n*2) and Space complexity: O(n*2)
int memorization(int ind,int n,int value,vector<int>&arr,vector<vector<int>>&dp)
{
    if(ind==n) return 0;

    if(dp[ind][value]!=-1) return dp[ind][value];

    int ans=0;

    if(value)
    {
        ans=max(-arr[ind]+memorization(ind+1,n,0,arr,dp), memorization(ind+1,n,1,arr,dp));
    }
    else
    {
        ans=max(arr[ind]+memorization(ind+1,n,1,arr,dp),memorization(ind+1,n,0,arr,dp));
    }
    return dp[ind][value]=ans;
}
// Time complexity: O(n*2) and Space complexity: O(n*2)
int tabulation(int n,vector<int>arr,vector<vector<int>>&dp)
{
    dp[n][0]=dp[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            int ans=0;
            if(j)
            {
                ans=max(-arr[i]+dp[i+1][0], dp[i+1][1]);
            }
            else
            {
                ans=max(arr[i]+dp[i+1][1], dp[i+1][0]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][1];
}
// Time complexity: O(n) and Space complexity: O(1)
int space_optimization(int n,vector<int>&arr)
{
    vector<int>ahead(2,0),curr(2,0);
    ahead[0]=ahead[1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            int ans=0;
            if(j)
            {
                ans=max(-arr[i]+ahead[0], ahead[1]);
            }
            else
            {
                ans=max(arr[i]+ahead[1], ahead[0]);
            }
            curr[j]=ans;
        }
        ahead=curr;
    }
    return ahead[1];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the recursion: "<<recursion(0,n,-1,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    cout<<"Answer using memorization: "<<memorization(0,n,1,arr,dp)<<endl;
    vector<vector<int>>dp1(n+1,vector<int>(2,0));
    cout<<"Answer using Tabulation method: "<<tabulation(n,arr,dp1)<<endl;
}

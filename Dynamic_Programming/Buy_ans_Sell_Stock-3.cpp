#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// You are given an array of the prices of the stock on n days. You can perform multiple buy and a sell operation so that
// you will get the maximum profit. Note that you can only buy the stock if you have not bought it before and you can only sell the stock if you have bought it before.
// In this problem, you can perform at most 2 transactions. You can buy and sell the stock multiple times but you can only perform at most 2 transactions.
// Time complexity: O(2^n) and Space complexity: O(n)
int recursion(int ind,int n,int cap,int buy,vector<int>&arr)
{
    if(ind==n || cap==0) return 0;

    if(buy==1)
    {
        return max(-arr[ind]+recursion(ind+1,n,cap,0,arr),recursion(ind+1,n,cap,1,arr));
    }
    else
    {
        return max(arr[ind]+recursion(ind+1,n,cap-1,1,arr),recursion(ind+1,n,cap,0,arr));
    }
}
// Time complexity: O(n*2*3) and Space complexity: O(n*2*3)
// The 3 is for the cap, 2 is for the buy and n is for the index.
int memorization(int ind,int n,int cap,int buy,vector<int>&arr,vector<vector<vector<int>>>&dp)
{
    if(ind==n || cap==0) return 0;

    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

    if(buy==1)
    {
        return dp[ind][buy][cap]=max(-arr[ind]+memorization(ind+1,n,cap,0,arr,dp),memorization(ind+1,n,cap,1,arr,dp));
    }
    else
    {
        return dp[ind][buy][cap]=max(arr[ind]+memorization(ind+1,n,cap-1,1,arr,dp),memorization(ind+1,n,cap,0,arr,dp));
    }
}
// Time complexity: O(n*2*3) and Space complexity: O(n*2*3+n) where n is for the recursion stack space.
int tabulation(int n,vector<int>arr,vector<vector<vector<int>>>&dp)
{
    /*
    Base case:1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            dp[i][j][0]=0;
        }
    }
    Base Case 2:
    for(int buy=0;buy<=1;buy++)
    {
        for(int cap=0;cap<3;cap++)
        {
            dp[n][buy][cap]=0;
        }
    }
    Just for Understanding
    */

    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<3;cap++)
            {
                if(buy==1)
                {
                    dp[i][buy][cap]=max(-arr[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                }
                else
                {
                    dp[i][buy][cap]=max(arr[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
// Time complexity: O(n) and Space complexity: O(1)
// Space optimization: We can use only 2 arrays instead of 3D array.
int space_optimization(int n,vector<int>&arr)
{
    vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<3;cap++)
            {
                if(buy==1)
                {
                    curr[buy][cap]=max(-arr[i]+after[0][cap],after[1][cap]);
                }
                else
                {
                    curr[buy][cap]=max(arr[i]+after[1][cap-1],after[0][cap]);
                }
            }
        }
        after=curr;
    }
    return curr[1][2];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the recursion: "<<recursion(0,n,2,1,arr)<<endl;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    cout<<"Answer using memorization: "<<memorization(0,n,2,1,arr,dp)<<endl;
    vector<vector<vector<int>>> dp1(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    cout<<"Answer using Tabulation method: "<<tabulation(n,arr,dp1)<<endl;
}
/*
Test case:
8
3 3 5 0 0 3 1 4
*/

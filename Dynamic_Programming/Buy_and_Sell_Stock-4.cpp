#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// You are given an array of the prices of the stock on n days. You can perform multiple buy and a sell operation so that
// you will get the maximum profit. Note that you can only buy the stock if you have not bought it before and you can only sell the stock if you have bought it before.
// In this problem, you can perform at most k transactions. You can buy and sell the stock multiple times but you can only perform at most k transactions.
// Time complexity: O(2^n) and Space complexity: O(n)
int recursion(int ind,int n,int transaction_no,vector<int>&arr,int k)
{
    if(ind==n || transaction_no == 2*k) return 0;

    if(transaction_no%2 == 0)
    {
        return max(-arr[ind]+recursion(ind+1,n,transaction_no+1,arr,k), recursion(ind+1,n,transaction_no,arr,k));
    }
    return max(arr[ind]+recursion(ind+1,n,transaction_no+1,arr,k), recursion(ind+1,n,transaction_no,arr,k));
}
// Time complexity: O(n*2*k) and Space complexity: O(n*2*k)
int memorization(int ind,int n,int transaction_no,vector<int>&arr,vector<vector<int>>&dp,int k)
{
    if(ind==n || transaction_no == 2*k) return 0;

    if(dp[ind][transaction_no] != -1) return dp[ind][transaction_no];

    if(transaction_no%2 == 0)
    {
        return dp[ind][transaction_no]=max(-arr[ind]+memorization(ind+1,n,transaction_no+1,arr,dp,k), memorization(ind+1,n,transaction_no,arr,dp,k));
    }
    return dp[ind][transaction_no]=max(arr[ind]+memorization(ind+1,n,transaction_no+1,arr,dp,k), memorization(ind+1,n,transaction_no,arr,dp,k));
}
// Time complexity: O(n*2*k) and Space complexity: O(n*2*k+n)
int tabulation(int n,vector<int>arr,vector<vector<int>>&dp,int k)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2*k-1;j>=0;j--)
        {
            if(j%2==0)
            {
                dp[i][j]=max(-arr[i]+dp[i+1][j+1],dp[i+1][j]);
            }
            else
            {
                dp[i][j]=max(arr[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}
// Time complexity: O(n*2*k) and Space complexity: O(2*k) where k is the number of transactions.
int space_optimization(int n,vector<int>&arr,int k)
{
    vector<int>after(2*k+1,0),curr(2*k+1,0);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2*k-1;j>=0;j--)
        {
            if(j%2==0)
            {
                curr[j]=max(-arr[i]+after[j+1],after[j]);
            }
            else
            {
                curr[j]=max(arr[i]+after[j+1],after[j]);
            }
        }
        after=curr;
    }
    return after[0];
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the recursion: "<<recursion(0,n,0,arr,k)<<endl;
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    cout<<"Answer using memorization: "<<memorization(0,n,0,arr,dp,k)<<endl;
    vector<vector<int>> dp1(n+1,vector<int>(2*k + 1,0));
    cout<<"Answer using Tabulation method: "<<tabulation(n,arr,dp1,k)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,arr,k)<<endl;
}
/*
Test case:
8 3
3 3 5 0 0 3 1 4
*/

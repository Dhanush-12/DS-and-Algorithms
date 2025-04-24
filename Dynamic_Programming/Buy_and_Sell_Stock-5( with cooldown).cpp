#include<bits/stdc++.h>
using namespace std;
// Similar problem as the previous buy and sell stocks problems but, only condition is that we should not buy
// any stock immediatly after selling the previous stock.
// Time complexity: O(2^n) and Space complexity: O(n)
int recursion(int ind,int buy,int n,vector<int>&arr)
{
    if(ind>=n) return 0;
    
    if(buy == 1)
    {
        return max(-arr[ind]+recursion(ind+1,0,n,arr), recursion(ind+1,1,n,arr));
    }
    return max(arr[ind]+recursion(ind+2,1,n,arr), recursion(ind+1,0,n,arr));
}
// Time Complexity: O(n*2), Space Complexity: O(n*2 + n)
int memorization(int ind,int buy,int n,vector<int>&arr,vector<vector<int>>&dp)
{
    if(ind>=n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy == 1)
    {
        return dp[ind][buy] = max(-arr[ind]+memorization(ind+1,0,n,arr,dp), memorization(ind+1,1,n,arr,dp));
    }
    return dp[ind][buy] = max(arr[ind]+memorization(ind+2,1,n,arr,dp), memorization(ind+1,0,n,arr,dp));
}
// Time Complexity: O(n*2) and Space Complexity (n*2)
int tabulation(int n,vector<int>&arr, vector<vector<int>>&dp)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            if(j==1)
            {
                dp[i][j] = max(-arr[i]+dp[i+1][0], dp[i+1][1]);
            }
            else
            {
                dp[i][j] = max(arr[i]+dp[i+2][1], dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
}
// Time Complexity: O(n), Space Complexity: O(1)
int space_optimization(int n,vector<int>&arr)
{
    vector<int>front1(2,0),front2(2,0),curr(2,0);
    for(int i=n-1;i>=0;i--)
    {
        curr[1]=max(-arr[i]+front1[0], front1[1]);
        curr[0]=max(arr[i]+front2[1], front2[0]);
        
        front2=front1;
        front1=curr;
    }
    return curr[1];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the recursion: "<<recursion(0,1,n,arr)<<endl;
    vector<vector<int>>dp(n, vector<int>(2,-1));
    cout<<"Answer using Memorization: "<<memorization(0,1,n,arr,dp)<<endl;
    vector<vector<int>> dp1(n+2,vector<int>(2,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,arr,dp1);
}

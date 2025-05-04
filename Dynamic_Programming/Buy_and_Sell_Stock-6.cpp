#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Similar problem as the previous buy and sell stocks problems but, each transaction has a fee associated with it.
// Time complexity: O(2^n) and Space complexity: O(n)
int recursion(int ind,int n,int transaction_no,vector<int>&arr,int fee)
{
    if(ind==n) return 0;

    if(transaction_no%2 == 0)
    {
        return max(-arr[ind]+recursion(ind+1,n,transaction_no+1,arr,fee), recursion(ind+1,n,transaction_no,arr,fee));
    }
    return max(arr[ind]-fee+recursion(ind+1,n,transaction_no+1,arr,fee), recursion(ind+1,n,transaction_no,arr,fee));
}
// Time Complexity: O(n*2), Space Complexity: O(n*2 + n)
int memorization(int ind,int n,int transaction_no,vector<int>&arr,vector<vector<int>>&dp,int fee)
{
    if(ind==n) return 0;

    if(dp[ind][transaction_no] != -1) return dp[ind][transaction_no];

    if(transaction_no%2 == 0)
    {
        return dp[ind][transaction_no]=max(-arr[ind]+memorization(ind+1,n,transaction_no+1,arr,dp,fee), memorization(ind+1,n,transaction_no,arr,dp,fee));
    }
    return dp[ind][transaction_no]=max(arr[ind]-fee+memorization(ind+1,n,transaction_no+1,arr,dp,fee), memorization(ind+1,n,transaction_no,arr,dp,fee));
}
// Time Complexity: O(n*2) and Space Complexity (n*2)
int tabulation(int n,vector<int>arr,vector<vector<int>>&dp,int fee)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            if(j%2==0)
            {
                dp[i][j]=max(-arr[i]+dp[i+1][j+1],dp[i+1][j]);
            }
            else
            {
                dp[i][j]=max(arr[i]-fee+dp[i+1][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}
// Time Complexity: O(n), Space Complexity: O(1)
int space_optimization(int n,vector<int>&arr,int fee)
{
    int aheadNotBuy,aheadBuy,curBuy,curNotBuy;
    aheadBuy=aheadNotBuy=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        curNotBuy = max(arr[ind] + aheadBuy, aheadNotBuy);
        curBuy = max(-arr[ind]-fee+aheadNotBuy,aheadBuy);
        aheadBuy=curBuy;
        aheadNotBuy=curNotBuy;
    }
    return aheadBuy;
}
int main()
{
    int n,fee;
    cin>>n>>fee;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the recursion: "<<recursion(0,n,0,arr,fee)<<endl;
    vector<vector<int>> dp(n,vector<int>(fee+1,-1));
    cout<<"Answer using memorization: "<<memorization(0,n,0,arr,dp,fee)<<endl;
    vector<vector<int>> dp1(n+1,vector<int>(fee + 1,0));
    cout<<"Answer using Tabulation method: "<<tabulation(n,arr,dp1,fee)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,arr,fee)<<endl;
}
/*
Test case:
8 4
3 3 50 0 0 3 1 4
*/

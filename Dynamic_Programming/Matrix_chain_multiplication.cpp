#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
//Given a chain of matrices A1,..., An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices.
int recursion(int i,int j,vector<int>&arr)
{
    if(i==j) return 0;
    int mini=1000000007;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j] + recursion(i,k,arr) + recursion(k+1,j,arr);
        if(steps<mini) mini=steps;
    }
    return mini;
}
int memorization(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
{
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini=1000000007;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j] + memorization(i,k,arr,dp) + memorization(k+1,j,arr,dp);
        if(steps<mini) mini=steps;
    }
    return dp[i][j]=mini;
}
int tabulation(int n,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int mini=1000000007;
            for(int k=i;k<j;k++)
            {
                int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
                if(steps<mini)
                {
                    mini=steps;
                }
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using recursion: "<<recursion(1,n-1,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<"Answer using memorization: "<<memorization(1,n-1,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(n,0));
    cout<<"Answer using tabulation: "<<tabulation(n,arr,dp1)<<endl;
}
/*
5
1 3 5 4 7
*/

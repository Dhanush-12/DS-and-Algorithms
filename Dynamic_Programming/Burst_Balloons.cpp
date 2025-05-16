#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Time Complexity: O(n^3) and Space Complexity: O(n^2)+O(n)
int recursion(int i,int j,vector<int>&arr)
{
    if(i>j) return 0;
    int ans=INT_MIN;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=arr[i-1]*arr[ind]*arr[j+1] + recursion(i,ind-1,arr) + recursion(ind+1,j,arr);
        ans=max(ans,cost);
    }
    return ans;
}
// Time Complexity: O(n^3) and Space Complexity: O(n^2)
int memorization(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
{
    if(i>j) return 0;
    int ans=INT_MIN;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++)
    {
        int cost=arr[i-1]*arr[ind]*arr[j+1] + memorization(i,ind-1,arr,dp) + memorization(ind+1,j,arr,dp);
        ans=max(ans,cost);
    }
    return dp[i][j]=ans;
}
// Time Complexity ~~ o(N^3) and Space Complexity: O(n^2)
int tabulation(int n,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j) continue;
            int ans=INT_MIN;
            for(int ind=i;ind<=j;ind++)
            {
                int cost=arr[i-1]*arr[ind]*arr[j+1]+dp[i][ind-1]+dp[ind+1][j];
                ans=max(ans,cost);
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    cout<<"Answer using recursion: "<<recursion(1,n,arr)<<endl;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<"Answer using memorization: "<<memorization(1,n,arr,dp)<<endl;
    vector<vector<int>>dp1(n+2,vector<int>(n+2,0));
    cout<<"Answer using tabulation: "<<tabulation(n,arr,dp1)<<endl;
}
/*
4
1 5 3 8

167
*/

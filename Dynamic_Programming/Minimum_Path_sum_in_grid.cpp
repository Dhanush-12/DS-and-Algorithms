#include<bits/stdc++.h>
using namespace std;
// Minimum Path Sum: Given a grid, we have to move from top left corner cell to the bottom right corner cell by only moving right ans/or down. Each cell is asscociated
// with a value. We have to find the minimum sum of the path values to reach the n-1,m-1 cell.
// Time complexity: O(2^(n+m)) and Space Complexity: O(n+m)
int recursion(int i,int j,vector<vector<int>>&arr)
{
    if(i<0 || j<0) return INT_MAX;
    if(i==0 && j==0) return arr[0][0];
    int left=INT_MAX;
    if(j>0) left=recursion(i,j-1,arr);
    int up=INT_MAX;
    if(i>0) up=recursion(i-1,j,arr);
    return arr[i][j]+min(up,left);
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int memorization(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return arr[i][j];
    int left=INT_MAX;
    if(j>0) left=memorization(i,j-1,arr,dp);
    int up=INT_MAX;
    if(i>0) up=memorization(i-1,j,arr,dp);
    return dp[i][j]=arr[i][j]+min(left,up);
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int tabulation(int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    dp[0][0]=arr[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            int right=INT_MAX;
            if(j>0) right=arr[i][j]+dp[i][j-1];
            int down=INT_MAX;
            if(i>0) down=arr[i][j]+dp[i-1][j];
            dp[i][j]=min(right,down);
        }
    }
    return dp[n-1][m-1];
}
// Time Complexity: O(n*m) and Space Complexity: O(m)
int spaceOptimization(int n,int m,vector<vector<int>>&arr)
{
    vector<int>prev(m,0);
    prev[0]=arr[0][0];
    for(int i=1;i<m;i++)
    {
        prev[i]=arr[0][i]+prev[i-1];
    }
    for(int i=1;i<n;i++)
    {
        vector<int>curr(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            if(j==0)
            {
                curr[j]=arr[i][j]+prev[j];
                continue;
            }
            int right=arr[i][j]+curr[j-1];
            int down=arr[i][j]+prev[j];
            curr[j]=min(right,down);
        }
        prev=curr;
    }
    return prev[m-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    cout<<"Answer using the Recursion: "<<recursion(n-1,m-1,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,m-1,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(m,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,m,arr)<<endl;
}

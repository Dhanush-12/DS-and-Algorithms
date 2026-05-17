#include<bits/stdc++.h>
using namespace std;
// Unique Grid Paths: Initially, we are on the top left corner of the grid, we have to reach the bottom right corner by only moving right ans/or down directions
// If the cell has -1, it means it has an obstacle and we have to avoid entering into the cell.
// Find the total unique paths to reach the bottom right corner.
// Time complexity: O(2^(n+m)) and Space Complexity: O(n+m)
int recursion(int i,int j,vector<vector<int>>&arr)
{
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    int up=0;
    if(i>0 && arr[i-1][j]!=-1) up=recursion(i-1,j,arr);
    int left=0;
    if(j>0 && arr[i][j-1]!=-1) left=recursion(i,j-1,arr);
    return left+up;
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int memorization(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0;
    if(i>0 && arr[i-1][j]!=-1) up=memorization(i-1,j,arr,dp);
    int left=0;
    if(j>0 && arr[i][j-1]!=-1) left=memorization(i,j-1,arr,dp);
    return dp[i][j]=(left+up);
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int tabulation(int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(arr[0][0]==-1 || arr[n-1][m-1]==-1) return 0;
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            if(arr[i][j]==-1) dp[i][j]=0;
            else
            {
                int down=0,right=0;
                if(i>0) down=dp[i-1][j];
                if(j>0) right=dp[i][j-1];
                dp[i][j]=(right+down);
            }
        }
    }
    return dp[n-1][m-1];
}
// Time Complexity: O(n*m) and Space Complexity: O(m)
int spaceOptimization(int n,int m,vector<vector<int>>&arr)
{
    if(arr[0][0]==-1 || arr[n-1][m-1]==-1) return 0;
    vector<int>prev(m,0);
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]!=-1) prev[i]=1;
        else break;
    }
    for(int i=1;i<n;i++)
    {
        vector<int>curr(m,0);
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1) curr[j]=0;
            else
            {
                int down=0,right=0;
                if(i>0) down=prev[j];
                if(j>0) right=curr[j-1];
                curr[j]=(down+right);
            }
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

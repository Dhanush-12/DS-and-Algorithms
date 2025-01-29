#include<bits/stdc++.h>
using namespace std;
// Unique Grid Paths: Initially, we are on the top left corner of the grid, we have to reach the bottom right corner by only moving right ans/or down directions
// Find the total unique paths to reach the bottom right corner.
// Time complexity: O(2^(n+m)) and Space Complexity: O(n+m)
int recursion(int i,int j)
{
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    int left=recursion(i,j-1);
    int up=recursion(i-1,j);
    return left+up;
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int memorization(int i,int j,vector<vector<int>>&dp)
{
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int left=memorization(i,j-1,dp);
    int up=memorization(i-1,j,dp);
    return dp[i][j]=(left+up);
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int tabulation(int n,int m,vector<vector<int>>&dp)
{
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            if(i==0) dp[i][j]=dp[i][j-1];
            else if(j==0) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
// Time Complexity: O(n*m) and Space Complexity: O(m)
int spaceOptimization(int n,int m)
{
    vector<int>prev(m,1);
    for(int i=1;i<n;i++)
    {
        vector<int>temp(m,0);
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                temp[j]=prev[j];
                continue;
            }
            temp[j]=temp[j-1]+prev[j];
        }
        prev=temp;
    }
    return prev[m-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"Answer using the Recursion: "<<recursion(n-1,m-1)<<endl;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,m-1,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(m,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,m)<<endl;
}

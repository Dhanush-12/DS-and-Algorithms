#include<bits/stdc++.h>
using namespace std;
// Minimum Path Sum in Triangle: Given a grid of type triangle (the ith row contains i+1 elements. We have to find the minimum path sum of the elements by only
// moving to the down or down_right of the grid.
// Time Complexity: O(2^n) and Space Complexity: O(n)
int recursion(int i,int j,int n,vector<vector<int>>&arr)
{
    if(i==n-1) return arr[i][j];
    int down=arr[i][j]+recursion(i+1,j,n,arr);
    int down_right=arr[i][j]+recursion(i+1,j+1,n,arr);
    return min(down,down_right);
}
// Time Complexity: O(n^n) and Space Complexity: O(n)+O(n*n)
int memorization(int i,int j,int n,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(i==n-1) return arr[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=arr[i][j]+memorization(i+1,j,n,arr,dp);
    int down_right=arr[i][j]+memorization(i+1,j+1,n,arr,dp);
    return dp[i][j]=min(down,down_right);
}
//  Time Complexity: O(n*n) and Space Complexity: O(n*n)
int tabulation(int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    for(int i=0;i<m;i++)
    {
        dp[n-1][i]=arr[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            int down=arr[i][j]+dp[i+1][j];
            int down_right=arr[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down,down_right);
        }
    }
    return dp[0][0];
}
// Time Complexity: O(n*n) and Space Complexity: O(n)
int spaceOptimization(int n,int m,vector<vector<int>>&arr)
{
    vector<int>next(m,0);
    for(int i=0;i<m;i++)
    {
        next[i]=arr[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        vector<int>curr(i+1);
        for(int j=0;j<=i;j++)
        {
            int down=arr[i][j]+next[j];
            int down_right=arr[i][j]+next[j+1];
            curr[j]=min(down,down_right);
        }
        next=curr;
    }
    return next[0];
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int a;
            cin>>a;
            arr[i].push_back(a);
        }
    }
    int m=arr[n-1].size();
    cout<<"Answer using the Recursion: "<<recursion(0,0,n,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<"Answer using Memorization: "<<memorization(0,0,n,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(m,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,m,arr)<<endl;
}

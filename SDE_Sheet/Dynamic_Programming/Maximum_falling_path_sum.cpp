#include<bits/stdc++.h>
#define inf 1000000009
using namespace std;
// Maximum falling path sum: We are given a grid, we start from any cell from the first row of the grid, we can move to any valid down/right diagonal cell/left diagonal cell
// of the next cell. Each cell consists of some value. We have to find the maximum sum of value we hold as we reach the last row of the grid.
// Time Complexity: O(3^n) and Space Complexity: O(n)
int recursion(int i,int j,int m,vector<vector<int>>&arr)
{
    if(j<0 || j>=m) return -inf;
    if(i==0) return arr[0][j];
    int up=arr[i][j]+recursion(i-1,j,m,arr);
    int up_left=arr[i][j]+recursion(i-1,j-1,m,arr);
    int up_right=arr[i][j]+recursion(i-1,j+1,m,arr);
    return max(up,max(up_left,up_right));
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int memorization(int i,int j,int m,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(j<0 || j>=m) return -inf;
    if(i==0) return arr[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int up=arr[i][j]+memorization(i-1,j,m,arr,dp);
    int up_left=arr[i][j]+memorization(i-1,j-1,m,arr,dp);
    int up_right=arr[i][j]+memorization(i-1,j+1,m,arr,dp);
    return dp[i][j]=max(up,max(up_left,up_right));
}
// Time Complexity: O(n*m) and Space Complexity: O(n*m)
int tabulation(int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    for(int i=0;i<m;i++) dp[0][i]=arr[0][i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int down=arr[i][j]+dp[i-1][j],ld=arr[i][j],rd=arr[i][j];
            if(j>0) ld+=dp[i-1][j-1];
            else ld+=(-inf);
            if(j<m-1) rd+=dp[i-1][j+1];
            else rd+=(-inf);
            dp[i][j]=max({down,ld,rd});
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());
}
// Time Complexity: O(n*m) and Space Complexity: O(m)
int spaceOptimization(int n,int m,vector<vector<int>>&arr)
{
    vector<int>prev(m,0);
    for(int i=0;i<m;i++) prev[i]=arr[0][i];
    for(int i=1;i<n;i++)
    {
        vector<int>curr(m,0);
        for(int j=0;j<m;j++)
        {
            int down=arr[i][j]+prev[j];
            int ld=arr[i][j],rd=arr[i][j];
            if(j>0) ld+=prev[j-1];
            else ld+=(-inf);
            if(j<m-1) rd+=prev[j+1];
            else rd+=(-inf);
            curr[j]=max({down,ld,rd});
        }
        prev=curr;
    }
    return *max_element(prev.begin(),prev.end());
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans=INT_MIN;
    for(int j=0;j<m;j++)
    {
        ans=max(ans,recursion(n-1,j,m,arr));
    }
    cout<<"Answer using the Recursion: "<<ans<<endl;
    ans=INT_MIN;
    for(int i=0;i<m;i++)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        ans=max(ans,memorization(n-1,i,m,arr,dp));
    }
    cout<<"Answer using Memorization: "<<ans<<endl;
    vector<vector<int>>dp1(n,vector<int>(m,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,m,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,m,arr)<<endl;
}

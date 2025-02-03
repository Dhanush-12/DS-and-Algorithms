#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Cherry Pickup: Given a grid in which each cell contains cherries given by the n*m matrix, Alice starts at top-left corner cell and Bob starts at top-right corner.
// They both are allowed to move down/down-left/down-right in the grid by picking up the all cherries being present in the current cell. Find out the maximum cherries
// they can pick up when they reach last row.
// Time complexity: O(3^n) and Space complexity: O(n)
int recursion(int i,int j1,int j2,int n,int m,vector<vector<int>>&arr)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -inf;
    if(i==n-1)
    {
        if(j1==j2)
        {
            return arr[i][j1];
        }
        else
        {
            return arr[i][j1]+arr[i][j2];
        }
    }
    int maxi=0;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            if(j1==j2) maxi=max(maxi,arr[i][j1]+recursion(i+1,j1+dj1,j2+dj2,n,m,arr));
            else maxi=max(maxi,arr[i][j1]+arr[i][j2]+recursion(i+1,j1+dj1,j2+dj2,n,m,arr));
        }
    }
    return maxi;
}
// Time complexity: O(n*m*m) and Space complexity: O(n*m*m)
int memorization(int i,int j1,int j2,int n,int m,vector<vector<int>>&arr,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -inf;
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    if(i==n-1)
    {
        if(j1==j2)
        {
            return arr[i][j1];
        }
        else
        {
            return arr[i][j1]+arr[i][j2];
        }
    }
    int maxi=0;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            if(j1==j2) maxi=max(maxi,arr[i][j1]+recursion(i+1,j1+dj1,j2+dj2,n,m,arr));
            else maxi=max(maxi,arr[i][j1]+arr[i][j2]+recursion(i+1,j1+dj1,j2+dj2,n,m,arr));
        }
    }
    return dp[i][j1][j2]=maxi;
}
// Time complexity: O(n*m*m) and Space complexity: O(n*m*m)
int tabulation(int n,int m,vector<vector<int>>&arr)
{
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2) dp[n-1][j1][j2]=arr[n-1][j1];
            else dp[n-1][j1][j2]=arr[n-1][j1]+arr[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++)
                {
                    for(int dj2=-1;dj2<=1;dj2++)
                    {
                        int val=0;
                        if(j1==j2) val=arr[i][j1];
                        else val=arr[i][j1]+arr[i][j2];
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) val+=dp[i+1][j1+dj1][j2+dj2];
                        else val+=(-1e8);
                        maxi=max(maxi,val);
                    }
                }
                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
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
    cout<<"Answer using the Recursion: "<<recursion(0,0,m-1,n,m,arr)<<endl;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    cout<<"Answer using Memorization: "<<memorization(0,0,m-1,n,m,arr,dp)<<endl;
    cout<<"Answer using Tabulation: "<<tabulation(n,m,arr)<<endl;
}

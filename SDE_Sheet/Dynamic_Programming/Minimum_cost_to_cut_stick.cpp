#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int recursion(int i,int j,vector<int>&arr)
{
    if(i>j) return 0;
    int mini=1000000007;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=arr[j+1]-arr[i-1]+recursion(i,ind-1,arr)+recursion(ind+1,j,arr);
        mini=min(mini,cost);
    }
    return mini;
}
int memorization(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1000000007;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=arr[j+1]-arr[i-1]+memorization(i,ind-1,arr,dp)+memorization(ind+1,j,arr,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
int tabulation(int n,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j) continue;
            int mini=1000000007;
            for(int ind=i;ind<=j;ind++)
            {
                int cost=arr[j+1]-arr[i-1]+dp[i][ind-1]+dp[ind+1][j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n];
}
int main()
{
    int n,c;
    cin>>n>>c;
    vector<int>arr(c);
    for(int i=0;i<c;i++) cin>>arr[i];
    arr.push_back(n);
    arr.insert(arr.begin(),0);
    sort(arr.begin(),arr.end());
    cout<<"Answer using recursion: "<<recursion(1,c,arr)<<endl;
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    cout<<"Answer using memorization: "<<memorization(1,c,arr,dp)<<endl;
    vector<vector<int>>dp1(c+2,vector<int>(c+2,0));
    cout<<"Answer using tabulation: "<<tabulation(c,arr,dp1)<<endl;
}
/*
5
1 3 5 4 7
*/

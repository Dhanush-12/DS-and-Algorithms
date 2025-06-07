#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Time complexity : O(n*m)
// Space Complexity : O(n*m)
int countSquareSubMatrixWithAllOne(vector<vector<int>>&arr,int n,int m)
{
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++) dp[0][j]=arr[0][j];
    for(int i=0;i<n;i++) dp[i][0]=arr[i][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==0) dp[i][j]=0;
            else
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=accumulate(dp[i].begin(),dp[i].end(),0);
    }
    return sum;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<countSquareSubMatrixWithAllOne(arr,n,m)<<endl;
}
/*

*/

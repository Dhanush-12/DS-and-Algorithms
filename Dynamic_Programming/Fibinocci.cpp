#include<bits/stdc++.h>
using namespace std;
// Time complexity of recursion is O(2^n) and space complexity is O(n)
int recursion(int n)
{
    if(n<=1) return n;
    return recursion(n-1)+recursion(n-2);
}
// Time complexity of memorization is O(n) and space complexity is O(n)
int memorization(int n,vector<int>&dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=memorization(n-1,dp)+memorization(n-2,dp);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<"Answer using recursion: "<<recursion(n)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Answer using memorization: "<<memorization(n,dp)<<endl;
    vector<int>dp1(n+1,0);
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    // Time complexity of tabulation is O(n) and space complexity is O(n)
    cout<<"Answer using tabulation: "<<dp[n]<<endl;
}

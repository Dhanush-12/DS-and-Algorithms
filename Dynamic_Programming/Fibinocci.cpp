#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(2^n) and Space Complexity: O(n)
int recursion(int n)
{
    if(n<=1) return n;
    return recursion(n-1)+recursion(n-2);
}
// Time Complexity: O(n) and Space Complexity: O(n)
int memorization(int n,vector<int>&dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=memorization(n-1,dp)+memorization(n-2,dp);
    return dp[n];
}
// Time Complexity: O(n) and Space Complexity: O(n)
int tabulation(int n,vector<int>&dp)
{
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// Time Complexity: O(n) and Space Complexity: O(1)
int spaceOptimization(int n)
{
    if(n<=1) return 1;
    int prev=0,curr=1;
    for(int i=2;i<=n;i++)
    {
        int temp=prev+curr;
        prev=curr;
        curr=temp;
    }
    return curr;
}
int main()
{
    int n;
    cin>>n;
    cout<<"Answer using recursion: "<<recursion(n)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Answer using memorization: "<<memorization(n,dp)<<endl;
    vector<int>dp1(n+1,0);
    cout<<"Answer using tabulation: "<<tabulation(n,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n)<<endl;
}

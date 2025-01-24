#include<bits/stdc++.h>
using namespace std;
// A frog has to reach the nth step from the current, it can only jump to i+1 or i+2 .... i+kth step from current ith step, the cost of jumping from i to i+1th step is abs(arr[i+1]-arr[i]).
// Return the minimum cost to reach the nth step from initial step.
// Time Complexity: O(2^k), Space Complexity: O(N+N);
int recursion(int ind,int k,vector<int>&arr)
{
    if(ind==0) return 0;
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(ind-j>=0){
            int jump=abs(arr[ind]-arr[ind-j])+recursion(ind-j,k,arr);
            minSteps=min(minSteps,jump);
        }
    }
    return minSteps;
}
// Time Complexity: O(N*k), Space Complexity: O(N)
int memorization(int ind,int k,vector<int>&dp,vector<int>&arr)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(ind-j>=0)
        {
            int jump=abs(arr[ind]-arr[ind-j])+memorization(ind-j,k,dp,arr);
            minSteps=min(minSteps,jump);
        }
    }
    return dp[ind]=minSteps;

}
// Time Complexity: O(N*k), Space complexity: O(N);
int tabulation(int n,int k,vector<int>&dp,vector<int>&arr)
{
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
                minSteps=min(minSteps,jump);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}
int spaceOptimization(int n,int k,vector<int>&arr)
{
    // Space optimization for this problem is not required, as the space complexity will be the same as the tabulation.
    return recursion(n-1,k,arr);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using recursion: "<<recursion(n-1,k,arr)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Answer using memorization: "<<memorization(n-1,k,dp,arr)<<endl;
    vector<int>dp1(n,0);
    cout<<"Answer using tabulation: "<<tabulation(n,k,dp1,arr)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,k,arr)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
// Maximum sum of non Adjacent elements in an array.
// Time Complexity: O(2^N), Space Complexity: O(N);
int recursion(int ind,vector<int>&arr)
{
    if(ind<0) return 0;
    if(ind==0) return arr[0];
    int notpick=recursion(ind-1,arr);
    int pick=arr[ind]+recursion(ind-2,arr);
    return max(notpick,pick);
}
// Time complexity: O(N), Space Complexity: O(N);
int memorization(int ind,vector<int>&dp,vector<int>&arr)
{
    if(ind<0) return 0;
    if(ind==0) return arr[0];
    if(dp[ind]!=-1) return dp[ind];
    int notpick=memorization(ind-1,dp,arr);
    int pick=INT_MIN;
    pick=arr[ind]+memorization(ind-2,dp,arr);
    return dp[ind]=max(notpick,pick);
}
// Time Complexity: O(N), Space Complexity: O(N);
int tabulation(int n,vector<int>&dp,vector<int>&arr)
{
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        int notpick=dp[i-1];
        int pick=arr[i];
        if(i-2>=0) pick+=dp[i-2];
        dp[i]=max(pick,notpick);
    }
    return dp[n-1];
}
// Time Complexity: O(N), Space Complexity: O(1);
int spaceOptimization(int n,vector<int>&arr)
{
    int prevv=arr[0],prev=arr[0],curr=arr[0];
    for(int i=1;i<n;i++)
    {
        int notpick=prev;
        int pick=arr[i];
        if(i-2>=0) pick+=prevv;
        curr=max(pick,notpick);
        prevv=prev;
        prev=curr;
    }
    return curr;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using recursion: "<<recursion(n-1,arr)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Answer using memorization: "<<memorization(n-1,dp,arr)<<endl;
    vector<int>dp1(n,0);
    cout<<"Answer using tabulation: "<<tabulation(n,dp1,arr)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,arr)<<endl;
}

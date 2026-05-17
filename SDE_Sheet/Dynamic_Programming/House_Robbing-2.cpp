#include<bits/stdc++.h>
using namespace std;
// House Robber 2: This problem is similar to the Maximum sum of non_adjacent elements in an array, but in this case, the array is circular.
// This can be solved just by taking maximum of including and excluding the first element and last element, as the both elements are adjacent, and cannot be taken in a single findout.
// Time Complexity: O(2^n) and Space Complexity: O(n)
int recursion(int ind,vector<int>&arr)
{
    if(ind<0) return 0;
    if(ind==0) return arr[0];
    int notpick=recursion(ind-1,arr);
    int pick=arr[ind]+recursion(ind-2,arr);
    return max(notpick,pick);
}
// Time Complexity: O(n) and Space Complexity: O(n)
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
// Time Complexity: O(n) and Space Complexity: O(n)
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
// Time Complexity: O(n) and Space Complexity: O(1)
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
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            temp2.push_back(arr[i]);
            continue;
        }
        if(i==n-1)
        {
            temp1.push_back(arr[i]);
            continue;
        }
        temp1.push_back(arr[i]);
        temp2.push_back(arr[i]);
    }
    cout<<"Answer using recursion: "<<max(recursion(n-2,temp1),recursion(n-2,temp2))<<endl;
    vector<int>dp(n,-1);
    vector<int>dpp(n,-1);
    cout<<"Answer using memorization: "<<max(memorization(n-2,dp,temp1),memorization(n-2,dpp,temp2))<<endl;
    vector<int>dp1(n,0);
    vector<int>dp2(n,0);
    cout<<"Answer using tabulation: "<<max(tabulation(n-1,dp1,temp1),tabulation(n-1,dp2,temp2))<<endl;
    cout<<"Answer using Space Optimization: "<<max(spaceOptimization(n-1,temp1),spaceOptimization(n-1,temp2))<<endl;
}

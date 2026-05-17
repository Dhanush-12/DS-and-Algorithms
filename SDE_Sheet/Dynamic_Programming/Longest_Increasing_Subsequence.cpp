#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Longest Increasing Subsequence Problem
// Given an array of integers, find the length of the longest increasing subsequence in the array.
// Time complexity: O(2^n) and Space complexity: O(n)
int recursion(int ind,int last,int n,vector<int>&arr)
{
    if(ind==n) return 0;
    int not_take=recursion(ind+1,last,n,arr);
    int take=0;
    if(last==-1 || arr[ind]>arr[last])
    {
        take=1+recursion(ind+1,ind,n,arr);
    }
    return max(take,not_take);
}
// Time Complexity: O(n^2) and Space Complexity: O(n^2)
int memorization(int ind,int last,int n,vector<int>&arr,vector<vector<int>>&dp)
{
    if(ind==n) return 0;
    if(dp[ind][last+1]!=-1) return dp[ind][last+1];
    int not_take=memorization(ind+1,last,n,arr,dp);
    int take=0;
    if(last==-1 || arr[ind]>arr[last])
    {
        take=1+memorization(ind+1,ind,n,arr,dp);
    }
    return dp[ind][last+1]=max(take,not_take);
}
// Time Complexity: O(n^2) and Space Complexity: O(n^2)
int tabulation1(int n,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)
        {
            int len=dp[i+1][j+1];
            if(j==-1 || arr[i]>arr[j])
            {
                len=max(len, 1+dp[i+1][i+1]);
            }
            dp[i][j+1]=len;
        }
    }
    return dp[0][0];
}
// Print the longest increasing subsequence
void print_LIS(int n,vector<int>&arr,vector<int>&dp)
{
    vector<int>ans;
    int maxi=*max_element(dp.begin(),dp.end());
    for(int i=n-1;i>=0;i--)
    {
        if(dp[i]==maxi)
        {
            ans.push_back(arr[i]);
            maxi--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
// Time Complexity: O(n^2) and Space Complexity: O(n)
int tabulation2(int n,vector<int>&arr)
{
    vector<int>dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    print_LIS(n,arr,dp);
    cout<<"Length of LIS is: ";
    return *max_element(dp.begin(),dp.end());
}
// Time Complexity: O(n^2) and Space Complexity: O(n)
int space_optimization(int n,vector<int>&arr)
{
    vector<int>next(n+1,0),curr(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)
        {
            int len=next[j+1];
            if(j==-1 || arr[i]>arr[j])
            {
                len=max(len,1+next[i+1]);
            }
            curr[j+1]=len;
        }
        next=curr;
    }
    return curr[0];
}
// Time Complexity: O(nlogn) and Space Complexity: O(n)
int most_optimal(int n,vector<int>&arr)
{
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    return (int)temp.size();
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Answer using the recursion: "<<recursion(0,-1,n,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    cout<<"Answer using memorization: "<<memorization(0,-1,n,arr,dp)<<endl;
}
/*
8
10 9 2 5 30 70 101 188
*/

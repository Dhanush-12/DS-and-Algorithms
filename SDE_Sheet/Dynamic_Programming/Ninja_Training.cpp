#include<bits/stdc++.h>
using namespace std;
// Ninja Training: The problem basically states, that given n days where ninja can perform only 1 out of 3 tasks in a day and he cannot perform the same task on the
// day, for each task there is a allocated score, we have to find the maximum total score he can earn after n days of training.
// Time complexity: O(3^n) and Space Complexity: O(n)
int recursion(int ind,int last,vector<vector<int>>&arr)
{
    if(ind==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last) maxi=max(maxi,arr[ind][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int points= arr[ind][i]+recursion(ind-1,i,arr);
            maxi=max(maxi,points);
        }
    }
    return maxi;
}
// Time Complexity: O(n) and Space Complexity: O(n)
int memorization(int ind,int last,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(dp[ind][last]!=-1) return dp[ind][last];
    if(ind==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,arr[ind][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int points=arr[ind][i]+memorization(ind-1,i,arr,dp);
            maxi=max(maxi,points);
        }
    }
    return dp[ind][last]=maxi;
}
// Time Complexity: O(n) and Space Complexity: O(n)
int tabulation(int n,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    for(int i=0;i<3;i++)
    {
        dp[0][i]=arr[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int maxi=0;
            for(int k=0;k<3;k++)
            {
                if(j==k) continue;
                maxi=max(maxi,dp[i-1][k]);
            }
            dp[i][j]=arr[i][j]+maxi;
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());
}
// Time Complexity: O(n) and Space Complexity: O(1)
int spaceOptimization(int n,vector<vector<int>>&arr)
{
    vector<int>prev(3,0);
    for(int i=0;i<3;i++) prev[i]=arr[0][i];
    for(int i=1;i<n;i++)
    {
        vector<int>temp(3,0);
        for(int j=0;j<3;j++)
        {
            int maxi=0;
            for(int k=0;k<3;k++)
            {
                if(j==k) continue;
                maxi=max(maxi,prev[k]);
            }
            temp[j]=arr[i][j]+maxi;
        }
        prev=temp;
    }
    return *max_element(prev.begin(),prev.end());
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Answer using the Recursion: "<<recursion(n-1,3,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,3,arr,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(3,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,arr,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<spaceOptimization(n,arr)<<endl;
}
/*
3
10 40 70
20 50 80
30 60 90
*/

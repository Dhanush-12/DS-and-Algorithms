#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// A theif has a bag that can hold a maximum capacity of max_w. He entered into a house which contains the n items with weight of each item is represented with wt[i]
// (0<=i<n) and with the profit of each represented with profit[i]. Find the maximum profit the thief can have after stealing the items with total wt<=max_w
// Time Complexity: O(2^n) and Space Complexity: O(n);
int recursion(int ind,int max_wt,vector<int>&wt,vector<int>&profit)
{
   if(ind==0)
   {
       if(wt[0]<=max_wt) return profit[0];
       else return 0;
   }
   int not_take=recursion(ind-1,max_wt,wt,profit);
   int take=0;
   if(max_wt>=wt[ind]) take=profit[ind]+recursion(ind-1,max_wt-wt[ind],wt,profit);
   return max(take,not_take);
}
// Time Complexity: O(n*mx_wt) and Space Complexity: O(n*max_wt)+O(n);
int memorization(int ind,int mx_wt,vector<int>&wt,vector<int>&profit,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(mx_wt>=wt[ind]) return profit[ind];
        else return 0;
    }
    if(dp[ind][mx_wt]!=-1) return dp[ind][mx_wt];
    int not_take=memorization(ind-1,mx_wt,wt,profit,dp);
    int take=0;
    if(mx_wt>=wt[ind]) take=profit[ind]+memorization(ind-1,mx_wt-wt[ind],wt,profit,dp);
    return dp[ind][mx_wt]=max(take,not_take);
}
// Time Complexity: O(n*max_wt) and Space Complexity: O(n*max_wt);
int tabulation(int n,int mx_wt,vector<int>&wt,vector<int>&profit,vector<vector<int>>&dp)
{
    for(int i=wt[0];i<=mx_wt;i++) dp[0][i]=profit[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=mx_wt;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(j>=wt[i]) take=profit[i]+dp[i-1][j-wt[i]];
            dp[i][j]=max(take,not_take);
        }
    }
    return dp[n-1][mx_wt];
}
// Time Complexity: O(n*max_wt) and Space Complexity: O(max_wt);
int space_optimization(int n,int max_wt,vector<int>&wt,vector<int>&profit)
{
    vector<int>prev(max_wt+1,0),curr(max_wt+1,0);
    for(int i=wt[0];i<=max_wt;i++) prev[i]=profit[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=max_wt;j++)
        {
            int not_take=prev[j];
            int take=0;
            if(j>=wt[i]) take=profit[i]+prev[j-wt[i]];
            curr[j]=max(take,not_take);
        }
        prev=curr;
    }
    return prev[max_wt];
}
int main()
{
    int n,max_wt;
    cin>>n>>max_wt;
    vector<int>wt(n),profit(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    cout<<"Answer using the Recursion: "<<recursion(n-1,max_wt,wt,profit)<<endl;
    vector<vector<int>>dp(n,vector<int>(max_wt+1,-1));
    cout<<"Answer using Memorization: "<<memorization(n-1,max_wt,wt,profit,dp)<<endl;
    vector<vector<int>>dp1(n,vector<int>(max_wt+1,0));
    cout<<"Answer using Tabulation: "<<tabulation(n,max_wt,wt,profit,dp1)<<endl;
    cout<<"Answer using Space Optimization: "<<space_optimization(n,max_wt,wt,profit)<<endl;
}

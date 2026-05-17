#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int Number_of_Longest_Increasing_Subsequence(int n,vector<int>&arr)
{
    vector<int>dp(n,1),cnt(n,1);
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && 1+dp[j]>dp[i])
            {
                dp[i]=1+dp[j];
                cnt[i]=cnt[j];
            }
            else if(arr[j]<arr[i] && 1+dp[j]==dp[i])
            {
                cnt[i]+=cnt[j];
            }
        }
        maxi=max(maxi,dp[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==maxi) ans+=cnt[i];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<Number_of_Longest_Increasing_Subsequence(n,arr)<<endl;
}
/*
5
1 3 5 4 7
*/

#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(n^2)
int dp(int n,vector<int>&arr)
{
    vector<int>dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int optimal(int n,vector<int>&arr)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        if(ans.back()<arr[i])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans[lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin()]=arr[i];
        }
    }
    return ans.size();
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=optimal(n,arr);
    cout<<ans<<endl;
}

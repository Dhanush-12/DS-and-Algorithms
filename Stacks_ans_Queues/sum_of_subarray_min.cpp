#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int sum_of_subarray_mins(int n,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            mini=min(mini,arr[j]);
            ans=(ans+mini)%mod;
        }
    }
    return ans;
}
void pref_smallest_or_equal(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[0],0});
    ans.push_back(-1);
    for(int i=1;i<n;i++)
    {
        if(s.top().first<=arr[i])
        {
            ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
        else
        {
            while(!s.empty() && s.top().first>arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
}
void suffsmallest(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[n-1],n-1});
    ans.push_back(n);
    for(int i=n-2;i>=0;i--)
    {
        if(s.top().first<arr[i])
        {
            ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
        else
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(n);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
    reverse(ans.begin(),ans.end());
}
int optimal_sum_of_subarray_mins(int n,vector<int>&arr)
{
    int ans=0;
    vector<int>pse,nse;
    suffsmallest(n,arr,nse);
    pref_smallest_or_equal(n,arr,pse);
    /*for(int i=0;i<n;i++)
    {
        cout<<nse[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<pse[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        ans=(ans+(right*left*arr[i])%mod)%mod;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=optimal_sum_of_subarray_mins(n,arr);
    cout<<ans<<endl;
}
/*
8
1 4 6 7 3 7 8 1
*/

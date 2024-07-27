#include<bits/stdc++.h>
using namespace std;
int num_of_subarrays_with_sum_k(int n,int k,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int sum=arr[i];
        if(sum==k) ans++;
        for(int j=i+1;j<n;j++)
        {
            sum+=arr[j];
            if(sum==k) ans++;
        }
    }
    return ans;
}
int num_of_subarrays_with_sum_k(vector<int>&arr,int n,int k)
{
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        ans+=(mp[sum-k]);
        mp[sum]++;
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=num_of_subarrays_with_sum_k(n,k,arr);
    cout<<ans<<endl;
}

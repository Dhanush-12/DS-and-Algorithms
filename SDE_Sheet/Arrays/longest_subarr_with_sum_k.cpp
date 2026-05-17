#include<bits/stdc++.h>
#define ll long long
using namespace std;
int getlongestsubarr_with_sum_k(int n,vector<int>&arr,int k)
{
    map<ll,int>mp;
    ll sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            ans=max(ans,i+1);
        }
        ll rem=sum-k;
        if(mp.count(rem))
        {
            ans=max(ans,i-mp[rem]);
        }
        if(!mp.count(sum))
        {
            mp[sum]=i;
        }
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=getlongestsubarr_with_sum_k(n,arr,k);
    cout<<ans<<endl;
}

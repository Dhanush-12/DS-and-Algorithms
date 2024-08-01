#include<bits/stdc++.h>
using namespace std;
int brute(int n,int k,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x=0;
        for(int j=i;j<n;j++)
        {
            x^=arr[j];
            if(x==k)
            {
                ans++;
            }
        }
    }
    return ans;
}
int optimal(int n,int k,vector<int>&arr)
{
    int ans=0,x=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    for(int i=0;i<n;i++)
    {
        x^=arr[i];
        if(mp.count(x^k))
        {
            ans+=mp[x^k];
        }
        mp[arr[i]]++;
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=brute(n,k,arr);
    cout<<ans<<endl;
}

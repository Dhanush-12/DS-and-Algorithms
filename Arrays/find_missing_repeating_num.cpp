#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(n^2)
vector<int>brute(int n,vector<int>&arr)
{
    int rep=-1,miss=-1;
    vector<int>vis(n+1,0);
    int f=0;
    for(int i=0;i<n;i++)
    {
        vis[arr[i]]=1;
        if(f==1) continue;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                f=1;
                rep=arr[i];
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            miss=i;
            break;
        }
    }
    return {rep,miss};
}
// Time complexity : O(n * log(n))
vector<int>better(int n,vector<int>&arr)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    int rep=-1,miss=-1;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==2) rep=i;
        else if(mp[i]==0) miss=i;
    }
    return {rep,miss};
}
// Time complexity : O(n)
vector<int>optimal1(int n,vector<int>&arr)
{
    int rep,miss;
    int tot=(n*(n+1))/2;
    int totsq=(n*(n+1)*(2*n + 1))/6;
    int sum=0,sqsum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        sqsum+=(arr[i]*arr[i]);
    }
    int val1=sum-tot;
    int val2=sqsum-totsq;
    val2/=val1;
    int x=(val1+val2)/2;
    int y=x-val1;
    return {x,y};
}
vector<int>optimal2(int n,vector<int>&arr)
{
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr^=arr[i];
        xr^=(i+1);
    }
    int num=xr & ~(xr-1);
    int z=0,o=0;
    for(int i=0;i<n;i++)
    {
        if((arr[i] & num) != 0)
        {
            o^=arr[i];
        }
        else
        {
            z^=arr[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if((i&num)!=0)
        {
            o^=i;
        }
        else
        {
            z^=i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==z) cnt++;
    }
    if(cnt==z) return {z,o};
    return {o,z};
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=optimal2(n,arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}

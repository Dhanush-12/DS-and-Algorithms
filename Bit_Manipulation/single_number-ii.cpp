#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(n*log(n));
int bruteforce(int n,vector<int>&arr)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    for(auto it:mp)
    {
        if(it.second==1) return it.first;
    }
    return -1;
}
// Time complexity : O(n*32);
int better(int n,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<32;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]&(1<<i))
                cnt++;
        }
        if(cnt%3==1)
        {
            ans=ans|(1<<i);
        }
    }
    return ans;
}
// Time complexity : O(n*log(n));
int optimal1(int n,vector<int>arr)
{
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i+=3)
    {
        if(arr[i]!=arr[i-1]) return arr[i-1];
    }
    return arr[n-1];
}
int optimal2(int n,vector<int>&arr)
{
    int ones=0,twos=0;
    for(int i=0;i<n;i++)
    {
        ones=(ones^arr[i])&(~twos);
        twos=(twos^arr[i])&(~ones);
    }
    return ones;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<optimal2(n,arr)<<endl;
}

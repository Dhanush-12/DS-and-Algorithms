#include<bits/stdc++.h>
using namespace std;
// Time complexity O(2n + nlog(n));
int solve(int n,vector<int>&start,vector<int>&last)
{
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({start[i],last[i]});
    }
    sort(arr.begin(),arr.end(),[&](pair<int,int>a,pair<int,int>b)
         {
             if(a.second==b.second) return a.first<b.first;
             return a.second<b.second;
         });
    int ans=1;
    int last1=arr[0].second;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first>=last1)
        {
            ans++;
            last1=arr[i].second;
        }
    }
    return n-ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>start(n),last(n);
    for(int i=0;i<n;i++) cin>>start[i];
    for(int i=0;i<n;i++) cin>>last[i];
    cout<<solve(n,start,last)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n + nlog(n));
int solve(int n,vector<int>&p,vector<int>&wt,int W)
{
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({p[i],wt[i]});
    }
    sort(arr.begin(),arr.end(),[&](pair<int,int>a,pair<int,int>b)
         {
             return (a.first/a.second)>(b.first/b.second);
         });
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(W==0) break;
        if(W>=arr[i].second)
        {
            ans+=arr[i].first;
            W-=arr[i].second;
        }
        else
        {
            ans+=((arr[i].first*W)/arr[i].second);
        }
        //cout<<ans<<endl;
    }
    return ans;
}
int main()
{
    int n,W;
    cin>>n>>W;
    vector<int>prof(n);
    vector<int>wt(n);
    for(int i=0;i<n;i++) cin>>prof[i];
    for(int i=0;i<n;i++) cin>>wt[i];
    cout<<solve(n,prof,wt,W)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
vector<pair<int,int>>solve(int n,vector<pair<int,int>>&arr,int l,int r)
{
    vector<pair<int,int>>ans;
    int i=0;
    while(i<n && arr[i].second<l)
    {
       ans.push_back(arr[i]);
       i++;
    }
    while(i<n && arr[i].first<=r)
    {
        l=min(l,arr[i].first);
        r=max(r,arr[i].second);
        i++;
    }
    ans.push_back({l,r});
    while(i<n) ans.push_back(arr[i]),i++;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    int l,r;
    cin>>l>>r;
    arr=solve(n,arr,l,r);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
int solve(int n,vector<int>&arr)
{
    sort(arr.begin(),arr.end());
    int wtTime=0,t=0;
    for(int i=0;i<n;i++)
    {
        wtTime+=t;
        t+=arr[i];
    }
    //cout<<wtTime<<" "<<t<<endl;
    return wtTime/n;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n,arr)<<endl;
}

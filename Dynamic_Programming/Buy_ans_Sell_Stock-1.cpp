#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int solve(int n,vector<int>&arr)
{
    int mini=arr[0];
    int ans=0;
    for(int i=1;i<n;i++)
    {
        ans=max(ans,arr[i]-mini);
        mini=min(mini,arr[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n,arr)<<endl;
}

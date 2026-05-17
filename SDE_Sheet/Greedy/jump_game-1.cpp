#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
int solve(int n,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i>ans) return false;
        ans=max(ans,i+arr[i]);
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n,arr)<<endl;
}

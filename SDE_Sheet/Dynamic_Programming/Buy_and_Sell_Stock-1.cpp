#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// You are given an array of the prices of the stock on n days. You can perform a buy and a sell operation so that
// at the end of the array, you should get the maximum profit.
// Time complexity: O(n) and Space Complexity: O(1) 
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

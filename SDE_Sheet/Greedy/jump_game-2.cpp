#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
int solve(int n,vector<int>&arr)
{
    int ans=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(maxi>=(n-1)) return ans;
        if((i+arr[i])>maxi)
        {
            ans++;
            maxi=i+arr[i];
        }
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

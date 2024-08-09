#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>&arr,int k)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        int miss=arr[mid]-(mid+1);
        if(miss<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return high+k+1;
}
int bruteforce(int n,vector<int>&arr,int k)
{
    int ans=k;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k) ans++;
        else
        {
            if(ans==arr[i]) ans++;
            break;
        }
    }
    return ans+1;
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n,arr,k)<<endl;
}

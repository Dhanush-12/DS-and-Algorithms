#include <bits/stdc++.h>
using namespace std;
int helper(int mid,int n,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=((arr[i]+mid-1)/mid);
    }
    return ans;
}
int solve(int n,vector<int>&arr,int th)
{
    int ans=-1;
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    while(low<=high)
    {
        int mid=(low+high)>>1;
        int val=helper(mid,n,arr);
        if(val<=th)
        {
            ans=mid;
            high=mid-1;
        }
        else if(val>th)
        {
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n,th;
    cin >> n >> th;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<solve(n,arr,th)<<endl;
}

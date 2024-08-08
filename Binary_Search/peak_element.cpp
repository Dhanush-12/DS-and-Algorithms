#include<bits/stdc++.h>
#define nl endl
using namespace std;
int peak_element(int n,vector<int>&arr)
{
    if(n==1) return 0;
    int low=1,high=n-2;
    while(low<=high)
    {
        int mid=(low+(high-low)/2);
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        {
            return mid;
        }
        else if(arr[mid]>arr[mid-1]) low=mid+1;
        else high=mid-1;
    }
    if(arr[0]>arr[1]) return 0;
    if(arr[n-2]<arr[n-1]) return n-1;
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=peak_element(n,arr);
    cout<<"Index "<<ans<<": Element : "<<arr[ans]<<endl;
}

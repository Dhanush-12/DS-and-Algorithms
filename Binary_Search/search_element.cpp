#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(log(n))
int bin_search(int n,vector<int>&arr,int k)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        // for large tests, - mid=
        if(arr[mid]==k) return mid+1;
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main()
{
    int n,ele;
    cin>>n>>ele;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int index=bin_search(n,arr,ele);
    cout<<index<<endl;
}

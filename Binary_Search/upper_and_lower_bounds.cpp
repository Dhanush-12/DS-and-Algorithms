#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(log(n))
// smallest index such that : arr[ind]>=k
int lowerbound(int n,vector<int>&arr,int k)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(arr[mid]>=k)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(ans==-1) return -1;
    return arr[ans];
}
// Time complexity : O(log(n))
// smallest index such that : arr[ind]>k
int upperbound(int n,vector<int>&arr,int k)
{
    int ans=-1;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(arr[mid]>k)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(ans==-1) return ans;
    return arr[ans];
}
int main()
{
    int n,ele;
    cin>>n>>ele;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Lower bound is : "<<endl;
    cout<<lowerbound(n,arr,ele)<<endl;
    cout<<arr[lower_bound(arr.begin(),arr.end(),ele)-arr.begin()]<<endl;
    cout<<"Upper bound is : "<<endl;
    cout<<upperbound(n,arr,ele)<<endl;
    cout<<arr[upper_bound(arr.begin(),arr.end(),ele)-arr.begin()]<<endl;
}
#include<bits/stdc++.h>
#define nl endl
using namespace std;
int solve(int n,vector<int>&arr)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+(high-low)/2);
        if(mid>0)
        {
            if(arr[mid]==arr[mid-1])
            {
                if(mid&1) low=mid+1;
                else high=mid-1;
            }
            else if(arr[mid]==arr[mid+1])
            {
                if((mid+1)&1) low=mid+1;
                else high=mid-1;
            }
            else return arr[mid];
        }
        else if(mid<n-1)
        {
            if(arr[mid]==arr[mid-1])
            {
                if(mid&1) low=mid+1;
                else high=mid-1;
            }
            else if(arr[mid]==arr[mid+1])
            {
                if((mid+1)&1) low=mid+1;
                else high=mid-1;
            }
            else return arr[mid];
        }
        else
        {
            return arr[mid];
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n,arr)<<endl;
}

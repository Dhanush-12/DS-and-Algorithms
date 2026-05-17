#include<bits/stdc++.h>
using namespace std;
// without duplicates
int solvewithoutdup(int n,vector<int>&arr,int k)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(arr[mid]==k) return mid;
        else
        {
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<=k && arr[mid]>=k)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(arr[mid]<=k && arr[high]>=k)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
    }
    return -1;
}
// with duplicates
int solvewithdup(int n,vector<int>&arr,int k)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(arr[mid]==k) return mid;
        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=k && arr[mid]>=k)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            if(arr[mid]<=k && arr[high]>=k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
   int n,ele;
   cin>>n>>ele;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   cout<<solvewithoutdup(n,arr,ele)<<endl;
}

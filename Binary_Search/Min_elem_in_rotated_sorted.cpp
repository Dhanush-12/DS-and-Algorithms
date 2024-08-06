#include<bits/stdc++.h>
using namespace std;
pair<int,int>solve(int n,vector<int>&arr)
{
    int low=0,high=n-1;
    pair<int,int>p;
    int ans=INT_MAX;
    int ind=-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(arr[low]<=arr[high])
        {
            if(ans>arr[low])
            {
                ind=low;
                ans=arr[low];
            }
            break;
        }
        if(arr[low]<=arr[mid])
        {
            ans=min(ans,arr[low]);
            ind=low;
            low=mid+1;
        }
        else
        {
            ans=min(ans,arr[mid]);
            ind=mid;
            high=mid-1;
        }
    }
    p={ans,ind};
    return p;
}
int main()
{
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   pair<int,int>ans=solve(n,arr);
   cout<<"Minimum element in the rotated sorted array is : "<<ans.first<<endl;
   cout<<"The number of times the array is rotated is : "<<n-ans.second<<endl;
}

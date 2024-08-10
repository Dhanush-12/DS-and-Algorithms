#include<bits/stdc++.h>
using namespace std;
int canwealloc(int n,vector<int>&arr,int pages,int k)
{
    int cnt=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<=pages)
        {
            sum+=arr[i];
            continue;
        }
        else
        {
            cnt++;
            sum=arr[i];
        }
    }
    return cnt;
}
int solve(int n,vector<int>&arr,int k)
{
   int low=*max_element(arr.begin(),arr.end()),high=accumulate(arr.begin(),arr.end(),0);
   while(low<=high)
   {
       int mid=(low+high)>>1;
       int stud=canwealloc(n,arr,mid,k);
       if(stud>k)
       {
           low=mid+1;
       }
       else
       {
           high=mid-1;
       }
   }
   return low;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=solve(n,arr,m);
        cout<<ans<<endl;
    }
}
/*
6 4
0 3 4 7 9 10
*/

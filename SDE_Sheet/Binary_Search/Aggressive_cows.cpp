#include<bits/stdc++.h>
using namespace std;
bool canweplace(int n,vector<int>&arr,int dis,int k)
{
    int cnt=1,last=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-last>=dis)
        {
            cnt++;
            last=arr[i];
        }
        if(cnt==k) return 1;
    }
    return 0;
}
int solve(int n,vector<int>&arr,int k)
{
   int low=arr[0],high=arr[n-1]-arr[0];
   int ans;
   while(low<=high)
   {
       int mid=(low+high)>>1;
       if(canweplace(n,arr,mid,k))
       {
           ans=mid;
           low=mid+1;
       }
       else
       {
           high=mid-1;
       }
   }
   return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int ans=solve(n,arr,c);
        cout<<ans<<endl;
    }
}
/*
6 4
0 3 4 7 9 10
*/

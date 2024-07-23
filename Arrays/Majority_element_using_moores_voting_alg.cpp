#include<bits/stdc++.h>
#define ll long long
using namespace std;
int moores_voting(int n,vector<int>&arr)
{
    int ele=arr[0];
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele) cnt++;
        else if(arr[i]!=ele) cnt--;
        if(cnt==0)
        {
            if(i==n-1) return -1;
            ele=arr[i+1];
        }
    }
    return ele;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=moores_voting(n,arr);
    cout<<ans<<endl;
}

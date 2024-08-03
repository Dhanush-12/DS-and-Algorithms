#include<bits/stdc++.h>
using namespace std;
int cnt=0;
// Time complexity : O(n^2)
int brute(int n,vector<int>&arr)
{
    int maxi=INT_MIN;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int prod=1;
        for(int j=i;j<n;j++)
        {
            prod*=arr[j];
            if(prod>maxi)
            {
                maxi=prod;
                ans=max(ans,j-i+1);
            }
        }
    }
    return maxi;
    return ans;
}
// Time complexity : O(n);
int optimal(int n,vector<int>&arr)
{
    int p=1,s=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(p==0) p=1;
        if(s==0) s=1;

        p=p*arr[i];
        s=s*arr[n-i-1];
        ans=max(ans,max(p,s));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=brute(n,arr);
    cout<<ans<<endl;
    ans=optimal(n,arr);
    cout<<ans<<endl;
}

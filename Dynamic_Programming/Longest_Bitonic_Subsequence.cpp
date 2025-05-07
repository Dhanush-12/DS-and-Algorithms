#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int LongestBitonicSequence(int n,vector<int>&arr)
{
    vector<int>dp1(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
    }
    vector<int>dp2(n,1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[j]<arr[i])
            {
                dp2[i]=max(dp2[i],1+dp2[j]);
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<LongestBitonicSequence(n,arr)<<endl;
}
/*
8
1 11 2 10 4 5 2 1
*/

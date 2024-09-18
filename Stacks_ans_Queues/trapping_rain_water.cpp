#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(3n)
int trapping_rain_water(int n,vector<int>&arr)
{
    int ans=0;
    vector<int>pref(n),suff(n);
    pref[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=max(pref[i-1],arr[i]);
    }
    suff[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suff[i]=max(suff[i+1],arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans+=(min(pref[i],suff[i])-arr[i]);
    }
    return ans;
}
// Time complexity : O(n);
int optimal_trapping_rain_water(int n,vector<int>&arr)
{
    int ans=0;
    int leftmax=0,rightmax=0;
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]<=arr[j])
        {
            if(leftmax>arr[i])
            {
                ans+=(leftmax-arr[i]);
            }
            else
            {
                leftmax=arr[i];
            }
            i++;
        }
        else
        {
            if(rightmax>arr[j])
            {
                ans+=(rightmax-arr[j]);
            }
            else
            {
                rightmax=arr[j];
            }
            j--;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=optimal_trapping_rain_water(n,arr);
    cout<<ans<<endl;
}
/*
12
0 1 0 2 1 0 1 3 2 1 2 1
*/

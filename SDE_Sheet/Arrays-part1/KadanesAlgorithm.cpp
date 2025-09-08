#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Kadane's Algorithm
int maximumSubarray(int n, vector<int>&arr)
{
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0) sum=0;
        ans=max(ans,sum);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Maximum Subarray sum is: ";
    cout<<maximumSubarray(n,arr)<<endl;
}
/*
8
-2 -3 4 -1 -2 1 5 -3
*/

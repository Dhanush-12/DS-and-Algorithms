#include<bits/stdc++.h>
using namespace std;
// Given an array that contains both negative and positive integers, find the maximum product subarray.
// Time Complexity: O(n);
// Space Complexity: O(1);
int maximumProductSubarray(int n, vector<int>&arr)
{
    int ans = INT_MIN;
    int pref = 1, suff = 1;
    for(int i=0;i<n;i++)
    {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;

        pref *= arr[i];
        suff *= arr[i];

        ans = max(ans, max(pref, suff));
    }
    return ans;
}
int maxProductSubarray(int n, vector<int>&arr)
{
    int maxi = arr[0];
    int mini = arr[0];
    int ans = arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i] < 0)
        {
            swap(maxi, mini);
        }

        maxi = max(arr[i], maxi*arr[i]);
        mini = min(arr[i], mini*arr[i]);

        ans = max(ans, maxi);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxProductSubarray(n, arr)<<endl;
}

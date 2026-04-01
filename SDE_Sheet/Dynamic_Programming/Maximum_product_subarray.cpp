#include<bits/stdc++.h>
using namespace std;
// Given an array that contains both negative and positive integers, find the maximum product subarray.
// Time Complexity: O(n);
// Space Complexity: O(1);
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

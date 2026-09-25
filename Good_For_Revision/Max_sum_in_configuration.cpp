#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given an integer array arr[]. Find the maximum value of the sum of i*arr[i] for all
    0 ≤ i ≤ arr.size()-1. The only operation allowed is to rotate(clockwise or counterclockwise)
    the array any number of times.

    Input: arr[] = [3, 1, 2, 8]
    Output: 29

    Input: arr[] = [1, 2, 3]
    Output: 8

    Input: arr[] = [4, 13]
    Output: 13
*/
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = (int)arr.size();
        vector<int> suff(n, 0);
        suff[n-1] = arr[n-1];
        int sum = 0;
        for(int i=1;i<n;i++)
        {
            suff[n-i-1] = suff[n-i]+arr[n-i-1];
            sum += (i*arr[i]);
        }
        int ans = sum;
        int pref = 0;
        for(int i=1;i<n;i++)
        {
            sum -= suff[i];
            sum -= pref;
            sum += (arr[i-1]*(n-1));
            pref += arr[i-1];
            ans = max(ans, sum);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.maxSum(arr)<<endl;
}
#include<bits/stdc++.h>
using namespace std;

/*
    Problem: Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length greater than
    or equal to k.

    Examples:

    Input: arr[] = [1, -2, 2, -3], k = 3
    Output: 1
    Explanation: The sub-array of length at least 3 that produces greatest sum is [1, -2, 2]
*/

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = (int)arr.size();
        vector<long long> bestEnd(n, 0);
        bestEnd[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            bestEnd[i] = max((long long)arr[i], bestEnd[i-1]+arr[i]);
        }
        long long curr = 0ll;
        for(int i=0;i<k;i++) curr += arr[i];
        long long ans = curr;
        for(int i=k;i<n;i++)
        {
            curr += arr[i]-arr[i-k];
            long long pref = curr + max(0ll, bestEnd[i-k]);
            ans = max(ans, pref);
        }
        return ans;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.maxSumWithK(arr, k)<<endl;
}
/*
4 3
1 -2 2 -3

6 2
1 1 1 1 1 1
*/

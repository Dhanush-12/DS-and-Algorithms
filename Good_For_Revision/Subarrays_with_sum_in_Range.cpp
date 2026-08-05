#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r]
    (inclusive).

    A subarray is a contiguous sequence of elements within the array.

    Examples:

    Input: l = 3, r = 8, arr[] = [1, 4, 6]
    Output: 3
*/
class Solution {
    long long countAtMost(vector<int> &arr, long long x)
    {
        if(x < 0) return 0;

        long long ans = 0;
        long long sum = 0;
        int left = 0;
        for(int right = 0; right < arr.size(); right++)
        {
            sum += arr[right];
            while(sum > x)
            {
                sum -= arr[left];
                left++;
            }
            ans += (right-left+1);
        }
        return ans;
    }
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        return countAtMost(arr, r)-countAtMost(arr, l-1);
    }
};
int main()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.countSubarray(arr, l, r)<<endl;
}


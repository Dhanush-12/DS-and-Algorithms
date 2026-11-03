#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given an integer array arr[ ] and an integer k, the task is to check if the array
    arr[ ] could be divided into k non-empty subsets with equal sum of elements.
    Note: All elements of this array should be part of exactly one partition.

    Examples:

    Input: arr[] = [2, 1, 4, 5, 6], k = 3
    Output: true
    Explanation: We can divide above array into 3 parts with equal sum as (2, 4), (1, 5), (6)
    Input: arr[] = [2, 1, 5, 5, 6], k = 3
    Output: false
    Explanation: It is not possible to divide above array into 3 parts with equal sum.
*/
class Solution {
    // BackTracking Approach
    bool solve(vector<int> &arr, vector<bool> &vis, int currSum, int target, int cnt, int k)
    {
        if(cnt == k-1) return true;
        if(currSum == target)
        {
            return solve(arr, vis, 0, target, cnt+1, k);
        }

        for(int i=0;i<arr.size();i++)
        {
            if(!vis[i] && currSum+arr[i] <= target)
            {
                vis[i] = true;
                if(solve(arr, vis, currSum+arr[i], target, cnt, k)) return true;

                vis[i] = false;
            }
        }
        return false;
    }
  public:
    // BitMasking using dp
    // Time Complexity: O(n * 2^n)
    // Space Complexity: O(2^n)
    bool isPartK(vector<int> &arr, int k) {
        int n = (int)arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % k) return false;
        int target = sum / k;
        // vector<bool> vis(n, false);
        // return solve(arr, vis, 0, target, 0, k);

        sort(arr.rbegin(), arr.rend());
        if(arr[0] > target) return false;
        int totalMasks = (1 << n);
        vector<int> dp(totalMasks, -1);
        dp[0] = 0;
        
        for(int mask=0;mask<totalMasks;mask++)
        {
            if(dp[mask] == -1) continue;

            for(int i=0;i<n;i++)
            {
                if(!(mask & (1 << i)))
                {
                    if(dp[mask] + arr[i] <= target)
                    {
                        int newMask = mask | (1 << i);
                        dp[newMask] = (dp[mask] + arr[i]) % target;
                    }
                }
            }
        }

        return dp[totalMasks - 1] == 0;
    }
};
int main() 
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.isPartK(arr, k)<<endl;
}
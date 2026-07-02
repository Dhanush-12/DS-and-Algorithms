#include<bits/stdc++.h>
using namespace std;

/*

    Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the
    given array is divisible by k otherwise, return false.

    Examples:

    Input: arr[] = [3, 1, 7, 5] , k = 6
    Output: true

    Solution: This problem uses the Pigeonhole Principle and Modular Arithmetic to drastically reduce the complexity
    compared to the standard Subset Sum problem.

    1. Leverage the Pigeonhole Principle ((n > k))If the number of elements (n) in the array is strictly greater than (k),
        the answer is always true in (O(1)) time.Compute the prefix sums of the array modulo (k).There are (n) prefix sums,
        but only (k) possible remainders ((0) to (k-1)).By the Pigeonhole Principle, if (n > k), at least one remainder
        must be (0), or two prefix sums must share the exact same remainder. Subtracting those two prefixes yields a contiguous
        subarray sum perfectly divisible by (k).

    2. Formulate Dynamic Programming ((n <= k)): When (n <= k\), you can use Dynamic Programming to track achievable remainders.
       Instead of tracking actual subset sums (which can grow infinitely large), you only track the sum modulo (k).Let dp[r] be a
       boolean value indicating if a non-empty subset sum can yield a remainder r when divided by (k).
       State Transition: For each number num in the array, its remainder is rem = num % k.If a remainder r was previously achievable
       (dp[r] == true), then the new remainder (r + rem) % k also becomes achievable.
       The element itself can start a new subset: dp[rem] = true.

*/

class Solution {
    // Good but not optimal
    // Time Complexity: O(n*sum);
    // Space Complexity: O(n*sum);
    bool solve(int ind, int ans, int n, vector<int> &arr, int k, vector<vector<int>> &dp)
    {
        if(ind == n)
        {
            if(ans) return (ans%k == 0);
            return false;
        }

        if(dp[ind][ans] != -1) return dp[ind][ans];

        bool not_take = solve(ind+1, ans, n, arr, k, dp);
        bool take = take = solve(ind+1, ans+arr[ind], n, arr, k, dp);

        return dp[ind][ans] = (not_take || take);
    }
public:
    // Most optimial using Pigeonhole principle
    // Time Complexity: O(n*k)
    // Space Complexity: O(k)
    bool divisibleByK(vector<int>& arr, int k) {
        int n = (int)arr.size();
        if(n > k) return true;
        vector<int> dp(k, 0);
        for(int i=0;i<n;i++)
        {
            int rem = arr[i]%k;

            vector<int> next_dp = dp;
            next_dp[rem] = 1;
            for(int j=0;j<k;j++)
            {
                if(dp[j])
                {
                    next_dp[(j+rem)%k] = 1;
                }
            }
            dp = next_dp;
        }
        return dp[0];
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.divisibleByK(arr, k)<<endl;
}

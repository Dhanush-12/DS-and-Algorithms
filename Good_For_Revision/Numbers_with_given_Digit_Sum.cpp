#include<bits/stdc++.h>
using namespace std;

/*
    Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.

    An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
    If there exist no n digit number with sum of digits equal to given sum, return -1.
    Examples :

    Input: n = 2, sum = 2
    Output: 2
*/

class Solution {
    int solve(int pos,int n, int sum)
    {
        if(pos > n)
        {
            return sum == 0 ? 1 : 0;
        }

        int ways = 0;

        int startDigit = (pos == 1) ? 1 : 0;
        for(int digit = startDigit; digit <= 9; digit++)
        {
            if(sum-digit >= 0) ways += solve(pos+1, n, sum-digit);
        }
        return ways;
    }
  public:
  // Recursive way of Solving
    int countWaysRecursive(int n, int sum) {
        return solve(1, n, sum);
    }
    // Tabulation method of solving
    int countWays(int n, int sum) {
        if(9*n < sum) return -1;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int pos=0;pos<n;pos++)
        {
            for(int currsum = 0; currsum <= sum; currsum++)
            {
                if(dp[pos][currsum] == 0) continue;
                int firstDigit = (pos == 0) ? 1 : 0;
                for(int digit = firstDigit;digit <= 9; digit++)
                {
                    if(currsum+digit <= sum)
                    {
                        dp[pos+1][currsum+digit] += dp[pos][currsum];
                    }
                }
            }
        }
        return dp[n][sum] == 0 ? -1 : dp[n][sum];
    }
    // Space Optimized version
    int countWaysSpaceOptimized(int n, int sum) {
        if (sum > 9 * n) {
            return -1;
        }

        vector<long long> dp(sum + 1, 0);
        dp[0] = 1;
        for (int pos = 0; pos < n; pos++) {
            vector<long long> next(sum + 1, 0);
            int startDigit = (pos == 0 ? 1 : 0);
            for (int currentSum = 0; currentSum <= sum; currentSum++) {
                if (dp[currentSum] == 0) {
                    continue;
                }
                for (int digit = startDigit; digit <= 9; digit++) {
                    int newSum = currentSum + digit;
                    if (newSum <= sum) {
                        next[newSum] += dp[currentSum];
                    }
                }
            }
            dp = move(next);
        }

        return dp[sum] == 0 ? -1 : dp[sum];
    }
};
int main()
{
    int n, sum;
    cin>>n>>sum;
    Solution s;
    cout<<s.countWays(n, sum)<<endl;
}


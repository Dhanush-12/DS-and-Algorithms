#include<bits/stdc++.h>
using namespace std;

/*
    Problem : You are given an integer array nums.

    Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that
    satisfy the following conditions:

    The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
    The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
    Return the total number of such pairs.

    Since the answer may be very large, return it modulo 109 + 7.

    

    Example 1:

    Input: nums = [1,2,3,4]

    Output: 10
*/

/*
    Solution: The key idea is to stop thinking about which exact subsequences we form.

    We only need to track:

    What is the current GCD of seq1, and what is the current GCD of seq2?

    Each number has exactly three choices:

    Do not use it.
    Put it in seq1.
    Put it in seq2.

    Because an index can go to only one of these choices, the two subsequences automatically remain disjoint.

    1. DP state

    Let:

    dp[g1][g2]

    represent the number of ways to process some prefix of nums such that:

    GCD(seq1) = g1
    GCD(seq2) = g2

    We use GCD 0 to mean that the subsequence is still empty.

    This works because:

    gcd(0, x) = x

    So adding the first element to an empty subsequence is handled naturally.

    Initially, both subsequences are empty:

    dp[0][0] = 1
    2. Transition for each number

    Suppose the current number is x.

    For every existing state (g1, g2), we have three possibilities.

    Choice 1: Ignore x
    newDp[g1][g2] += dp[g1][g2]
    Choice 2: Add x to seq1

    The new GCD of seq1 becomes:

    gcd(g1, x)

    Therefore:

    newDp[gcd(g1, x)][g2] += dp[g1][g2]
    Choice 3: Add x to seq2
    newDp[g1][gcd(g2, x)] += dp[g1][g2]
    Dry run: nums = [1, 2]

    Start:

    dp[0][0] = 1
    Process 1

    From (0, 0):

    Ignore 1       → (0, 0)
    Put in seq1    → (1, 0)
    Put in seq2    → (0, 1)

    So:

    dp[0][0] = 1
    dp[1][0] = 1
    dp[0][1] = 1
    Process 2

    Consider state (1, 0):

    Ignore 2       → (1, 0)
    Put 2 in seq1  → (gcd(1,2), 0) = (1,0)
    Put 2 in seq2  → (1, gcd(0,2)) = (1,2)

    The same process is performed for every state.

    At the end, we count states where:

    g1 == g2
    g1 != 0

    We exclude g1 = g2 = 0 because both subsequences must be non-empty.

    Why equal non-zero GCD is sufficient

    A state such as:

    dp[2][2]

    means:

    GCD(seq1) = 2
    GCD(seq2) = 2

    Both subsequences must be non-empty because an empty subsequence is represented by GCD 0.

    Therefore the answer is:

    dp[1][1] + dp[2][2] + dp[3][3] + ...
    Example: nums = [1,2,3,4]

    Let us understand why the answer is 10.

    Because the array contains only one copy each of 2, 3, and 4, it is difficult for two disjoint subsequences to independently obtain GCD 2, 3, or 4.

    All valid pairs here have equal GCD 1.

    Some examples are:

    seq1 = [1],   seq2 = [2,3]
    seq1 = [1],   seq2 = [2,4,3]
    seq1 = [2,3], seq2 = [1]
    seq1 = [2,3], seq2 = [1,4]

    Notice that (seq1, seq2) is treated as an ordered pair.

    Therefore:

    ([1], [2,3])

    and

    ([2,3], [1])

    are two different pairs.

    The DP counts all 10 valid ordered pairs.

    Complexity

    Let:

    M = maximum value in nums
    N = nums.size()

    The DP has approximately:

    M × M

    states.

    For every number, we process all states:

    Time:  O(N × M² × log M)
    Space: O(M²)

    The log M factor comes from computing GCD, although in practice std::gcd is very fast.

    The main observation

    The difficult-looking part is:

    How do we generate two disjoint subsequences?

    You do not generate them explicitly.

    For every index, assign one of three labels:

    0 → unused
    1 → belongs to seq1
    2 → belongs to seq2

    Then maintain only:

    (GCD of seq1, GCD of seq2)

    So the complete recurrence is:

    dp after x =
        leave x unused
    + add x to seq1
    + add x to seq2

    and the final answer is:

    sum(dp[g][g]) for every g > 0
*/
class Solution {
    const int mod = 1000000007;
public:
    int subsequencePairCount(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(maxValue+1, vector<int>(maxValue+1, 0));
        dp[0][0] = 1;
        for(int x : nums)
        {
            vector<vector<int>> nextDp(maxValue+1, vector<int>(maxValue+1, 0));
            for(int g1 = 0; g1 <= maxValue; g1++)
            {
                for(int g2 = 0; g2 <= maxValue; g2++)
                {
                    if(dp[g1][g2] == 0) continue;

                    int ways = dp[g1][g2];

                    nextDp[g1][g2] = (nextDp[g1][g2]+ways)%mod;

                    int newG1 = __gcd(g1, x);
                    nextDp[newG1][g2] = (nextDp[newG1][g2]+ways)%mod;

                    int newG2 = __gcd(g2, x);
                    nextDp[g1][newG2] = (nextDp[g1][newG2] + ways) % mod;
                }
            }
            dp = move(nextDp);
        }
        long long ans = 0;
        for(int g=1;g<=maxValue;g++)
        {
            ans = (ans + dp[g][g]) % mod;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.subsequencePairCount(arr)<<endl;
}

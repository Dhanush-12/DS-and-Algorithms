// Need to Revisit
#include<bits/stdc++.h>
using namespace std;

/*
    Problem: Given an integer array arr[], count the number of different subsets whose product can be represented as a product of
    one or more distinct prime numbers.  Two subsets are considered different if the set of chosen array indexes are not same.

    Return the count modulo 109 + 7.

    Examples:

    Input: arr[] = [1, 2, 3, 4]
    Output: 6

    Solution: This is a classic bitmask DP problem (very similar to LeetCode 1994 - The Number of Good Subsets). The key observation
    is the product itself doesn't matter. What matters is which prime factors appear.

    Step 1: Understand the condition. A subset is valid if its product is

    p1×p2×...×pk

    where every prime appears at most once.

    For example

    6 = 2 × 3          ✔
    30 = 2 × 3 × 5     ✔
    42 = 2 × 3 × 7     ✔

    4 = 2²             ✘
    12 = 2² × 3        ✘
    18 = 2 × 3²        ✘

    So if any prime occurs twice in the final product, the subset is invalid.

    Step 2: Numbers that are immediately useless

    Consider

    4 = 2²
    8 = 2³
    9 = 3²
    12 = 2²×3
    18 = 2×3²
    20 = 2²×5

    These already contain repeated primes. If we include any of them, the subset can never become valid. So simply discard them.

    Step 3: Only square-free numbers remain. Example: 1,2,3,5,6,7,10,14,15,21,22,26,30. Each prime appears at most once.

    Represent every number by the primes it contains.

    Example:

    2  -> {2}
    3  -> {3}
    6  -> {2,3}
    10 -> {2,5}
    15 -> {3,5}
    30 -> {2,3,5}

    Step 4: Encode as a bitmask. Suppose primes = 2,3,5,7,11,13,17,19,23,29 (There are only 10 primes ≤ 30.)

    Assign

    2  -> bit0
    3  -> bit1
    5  -> bit2
    7  -> bit3
    ...
    29 -> bit9

    Examples:

    ---> 2 -> mask -> 0000000001

    ---> 6 = 2×3 -> mask -> 0000000011

    ---> 30 -> mask -> 0000000111

    Step 5: DP over masks

    Let dp[mask] = number of ways to obtain exactly this set of used primes.

    Initially, dp[0]=1 meaning choose nothing. Suppose current number is 6, mask = 0011, We try to add it to every previous mask.

    If oldMask & newMask == 0, then no prime repeats, So: dp[oldMask | newMask] += dp[oldMask]

    Otherwise skip it.

    Example:

    Current masks

    mask 0001 -> {2}, Take 0011 -> 0001 & 0011 = 0001, Non-zero, Prime 2 repeats, Cannot take.

    Another, mask -> 0100, {5} Take 6 -> 0011 -> 0100 & 0011 = 0000, No overlap, New mask -> 0111 -> Valid.

    Step 6: What about 1? 1 has no prime factors. Mask 0000000000. It can accompany every valid subset. Suppose there are cnt1 ones.

    Every valid subset can choose 0, 1, 2, ... , cnt1 ones independently. Hence multiply answer by 2^cnt1 at the end. Notice {1}

    alone is not valid because its product is 1 which is not a product of one or more primes. So subtract the empty subset before

    multiplying, or equivalently: answer = (sum(dp) - dp[0]) * 2^{cnt1}.

    Complexity: There are only 2^10 = 1024 masks. For every number, 1024 transitions

    Total

    O(N × 1024)

    which is essentially linear.
*/

class Solution {
    static const int mod = (int)1e9 + 7;
  public:
    int countSubsets(vector<int> &arr) {
        int n = (int)arr.size();
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        int ones = 0;
        vector<long long> dp(1<<10, 0);
        dp[0] = 1;
        for(int num : arr)
        {
            if(num == 1)
            {
                ones++;
                continue;
            }
            int mask = 0;
            bool valid = true;
            int temp = num;

            for(int i=0;i<10;i++)
            {
                int p = primes[i];
                int cnt = 0;
                while(temp % p == 0)
                {
                    temp /= p;
                    cnt++;
                }
                if(cnt > 1)
                {
                    valid = false;
                    break;
                }
                if(cnt == 1)
                {
                    mask |= (1 << i);
                }
            }
            if(!valid) continue;

            for(int oldmask = (1 << 10)-1; oldmask >= 0; oldmask--)
            {
                if((oldmask & mask) == 0)
                {
                    dp[oldmask | mask] = (dp[oldmask + mask] + dp[oldmask]) % mod;
                }
            }
        }
        long long ans = 0;
        for(int mask = 1; mask < (1 << 10); mask++)
        {
            ans = (ans + dp[mask]) % mod;
        }
        long long pow2 = 1;
        while(ones--)
        {
            pow2 = (pow2 * 2) % mod;
        }
        ans = (ans * pow2) % mod;
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
    cout<<s.countSubsets(arr)<<endl;
}
/*
4
1 2 3 4

3
2 2 3
*/

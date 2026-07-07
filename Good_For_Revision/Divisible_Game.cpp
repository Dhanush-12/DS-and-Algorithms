#include<bits/stdc++.h>
using namespace std;

/*
    Problem : You are given an integer array nums of length n. Alice and Bob are playing a game. Alice chooses:

    An integer k such that k > 1. Two integers l and r such that 0 <= l <= r < n. Initially, both Alice's and Bob's scores are 0.

    For each index i in the range [l, r] (inclusive): If nums[i] is divisible by k, Alice's score increases by nums[i].Otherwise, 
    Bob's score increases by nums[i].The score difference is Alice's score minus Bob's score.Alice wants to maximize the score 
    difference. If there are multiple values of k that achieve the maximum score difference, she chooses the smallest such k.

    Return the product of the maximum score difference and the chosen value of k. Since the result can be large, return it modulo 
    10^9 + 7.
    
    Example 1:
        Input: nums = [1,4,6,8]
        Output: 36
*/

class Solution {
    static const int mod = 1000000007;
    vector<int> getPrimeFactors(int n)
    {
        vector<int> factors;
        for(int i=2;1ll*i*i<=n;i++)
        {
            if(n%i == 0) {
                factors.push_back(i);
                while(n%i == 0) n /= i;
            }
        }
        if(n > 1) factors.push_back(n);
        return factors;
    }
public:
    int divisibleGame(vector<int>& nums) {
        set<int> f;
        for(int x : nums) {
            vector<int> factors = getPrimeFactors(x);
            for(int p : factors) f.insert(p);
        }
        if(f.empty())
        {
            return mod-2;
        }

        long long bestScore = LLONG_MIN;
        int bestK = 2;
        for(int k : f) {
            long long curr = LLONG_MIN;
            long long best = LLONG_MIN;
            for(int x : nums) {
                long long val = (x % k == 0) ? x : -x;
                if(curr == LLONG_MIN) curr = val;
                else curr = max(val, curr+val);

                best = max(best, curr);
            }
            if(best > bestScore) {
                bestScore = best;
                bestK = k;
            }
        }
        long long ans = ((bestScore % mod) * bestK) % mod;
        if(ans < 0) ans += mod;
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
    cout<<s.divisibleGame(arr)<<endl;
}

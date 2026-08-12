#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;
/*
    Porblem: You are an adventurer travelling through a mystical corridor with n sealed doors.

    Behind ith door, there lies a magical item that increases your mana(magic energy) by value arr[i]. To pass through each door, you
    must use one of two magical spells, each with its own trade-offs.

    The Purification Spell: A safe and reliable spell that opens a door without affecting the other treasures. However, it requires k units of mana per use.
    The Shadow Spell: A dark and powerful spell that opens a door for free but weakens the magic in all the remaining doors(including the current door), reducing the mana of the magic items behind them to half of their current value. The weakening process rounds down to the nearest whole number.
    Your goal is to maximize the total mana you receive after opening all the doors. You can draw upon extra mana reserves (even going negative) if needed to cast the Purification Spell.

    Note: You need to open all of the doors in the same sequence as they are provided.

    Examples:

    Input: arr[] = [3, 6, 9, 2], k = 4
    Output: 7
    Explanation:
    Use Purification Spell to open first door, mana balance = 0-4+3 = -1.
    Use Purification Spell to open second door, mana balance = -1-4+6 = 1.
    Use Purification Spell to open third door, mana balance = 1-4+9 = 6.
    Use Shadow Spell to open fourth door, mana of remaining items is reduced to half, mana balance = 6+(2/2) = 7.
*/
class Solution {
    // Time Complexity : O(n*32)
    // Space Complexity: O(n*32)
    long long solve(int ind, int n, vector<int> &arr, int k, int p, vector<vector<long long>> &dp)
    {
        if(ind == n) return 0ll;

        if(dp[ind][p] != LLONG_MIN) return dp[ind][p];

        long long current = (p >= 31 ? 0 : arr[ind] >> p);
        long long purificationSpell = current - k + solve(ind+1, n, arr, k, p, dp);

        long long shadow = (p >= 31 ? 0 : arr[ind] >> (p+1));
        long long shadowSpell = shadow + solve(ind+1, n, arr, k, min(31, p+1), dp);

        return dp[ind][p] = max(purificationSpell, shadowSpell);
    }
  public:
    long long collectMana(vector<int> &arr, int k) {
        int n = (int)arr.size();
        /*
        vector<vector<long long>> dp(n, vector<long long>(32, LLONG_MIN));
        return solve(0, n, arr, k, 0, dp);
        */
        vector<vector<long long>> dp(n+1, vector<long long>(32, 0));

        for(int i=n-1;i>=0;i--)
        {
            for(int p=30;p>=0;p--)
            {
                long long current = (arr[i] >> p);
                long long purificationSpell = current - k + dp[i+1][p];

                long long shadow = arr[i] >> (p+1);
                long long shadowSpell = shadow + dp[i+1][min(31, p+1)];

                dp[i][p] = max(purificationSpell, shadowSpell);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.collectMana(arr, k)<<endl;
}
/*
4 4
3 6 9 2

4 1
2 1 6 10
*/

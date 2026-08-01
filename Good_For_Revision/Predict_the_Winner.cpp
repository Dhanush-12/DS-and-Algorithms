#include<bits/stdc++.h>
using namespace std;

/*
    Porblem: You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

    Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the
    player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the
    array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

    Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you
    should also return true. You may assume that both players are playing optimally.

    Example 1:

    Input: nums = [1,5,2]
    Output: false
    Explanation: Initially, player 1 can choose between 1 and 2. 
    If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
    So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
    Hence, player 1 will never be the winner and you need to return false.

    Example 2:

    Input: nums = [1,5,233,7]
    Output: true
    Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
    Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

*/

class Solution {
    int solveRecursive(vector<int> &arr, int l, int r)
    {
        if(l == r) return arr[l];

        int left = arr[l] - solveRecursive(arr, l+1, r);
        int right = arr[r] - solveRecursive(arr, l, r-1);

        return max(left, right);
    }
    int solveMemoization(vector<int> &arr, int l, int r, vector<vector<int>> &dp)
    {
        if(l == r) return arr[l];

        if(dp[l][r] != INT_MIN) return dp[l][r];

        int left = arr[l] - solveMemoization(arr, l+1, r, dp);
        int right = arr[r] - solveMemoization(arr, l, r-1, dp);

        return dp[l][r] = max(left, right);
    }
    // Time Complexity : O(n^2)
    // Space Complexity : O(n^2)
    bool solveTabulation(int n, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++) dp[i][i] = arr[i];

        for(int len = 2;len <= n; len++)
        {
            for(int l = 0; l+len-1 < n; l++)
            {
                int r = l+len-1;
                dp[l][r] = max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = (int)nums.size();
        return solveTabulation(n, nums);
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.predictTheWinner(arr)<<endl;
}
/*
4
1 5 233 7
*/

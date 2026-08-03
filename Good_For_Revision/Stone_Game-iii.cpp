#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an
    associated value which is an integer given in the array stoneValue.

    Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first
    remaining stones in the row.

    The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

    The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be
    a tie. The game continues until all the stones have been taken.

    Assume Alice and Bob play optimally.

    Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.



    Example 1:

    Input: stoneValue = [1,2,3,7]
    Output: "Bob"
    Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7
    and Bob wins.

    Example 2:

    Input: stoneValue = [1,2,3,-9]
    Output: "Alice"
*/
class Solution {
    vector<int> dp;
    int n;
    int solve(int i, vector<int>&arr)
    {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = 0;
        int ans = INT_MIN;

        for(int k=0;k<3 && i+k < n; k++)
        {
            take += arr[i+k];
            ans = max(ans, take-solve(i+k+1, arr));
        }

        return dp[i] = ans;
    }
    int solveDP(int n, vector<int>& stoneValue)
    {
        vector<int> dp(n+3, 0);
        for(int i=n-1;i>=0;i--)
        {
            int take = 0;
            dp[i] = INT_MIN;
            for(int k=0;k<3 && i+k < n; k++)
            {
                take += stoneValue[i+k];
                dp[i] = max(dp[i], take-dp[i+k+1]);
            }
        }
        return dp[0];
    }
    int solveSpaceOptimized(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int>dp(3,0);
        for(int i=n-1;i>=0;i--){
            int t1 = stoneValue[i]-dp[(i+1)%3];
            int t2 = INT_MIN;
            if(i+1<n) t2 = stoneValue[i]+stoneValue[i+1]-dp[(i+2)%3];
            int t3 = INT_MIN;
            if(i+2<n) t3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[(i+3)%3];
            dp[i%3] =  max({t1,t2,t3});
        }
        return dp[0];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = (int)stoneValue.size();
        //dp.assign(n, -1);
        int diff = solveSpaceOptimized(stoneValue);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        return "Tie";
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.stoneGameIII(arr)<<endl;
}
/*
4
1 2 3 7

4
1 2 3 -9
*/

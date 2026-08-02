#include<bits/stdc++.h>
using namespace std;

/*
    Given two positive integer n and m. Find the number of arrays of size n that can be formed such that:

    Each element is in the range [1, m].
    All adjacent are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai+1 divides Ai.
    Examples:

    Input: n = 3, m = 3
    Output : 17
    Explanation: The possible arrays are [1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 1], [1, 2, 2], [1, 3, 1], [1, 3, 3], [2, 1, 1],
    [2, 1, 2], [2, 1, 3], [2, 2, 1], [2, 2, 2], [3, 1, 1], [3, 1, 2], [3, 1, 3], [3, 3, 1] and [3, 3, 3].
*/

class Solution {
    // Time Complexity: O(m^n)
    void solve(int n, int m, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=1;i<=m;i++)
        {
            if(temp.empty() || i%temp.back() == 0 || temp.back()%i == 0) temp.push_back(i);
            else continue;
            solve(n, m, temp, ans);
            temp.pop_back();
        }
        return;
    }
    // Time Complexity: O(n*m*m)
    // Space Complexity: O(n*m)
    int solveDP(int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=m;i++) dp[1][i] = 1;
        for(int len=2;len<=n;len++)
        {
            for(int last=1;last<=m;last++)
            {
                for(int prev=1;prev<=m;prev++)
                {
                    if(last % prev == 0 || prev % last == 0)
                    {
                        dp[len][last] += dp[len-1][prev];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++) ans += dp[n][i];
        return ans;
    }
    // Time Complexity: O(n*m*log(m))
    // Space Complexity: O(m)
    int solveMostOptimal(int n, int m)
    {
        vector<vector<int>> divisors(m+1);
        for(int d=1;d<=m;d++)
        {
            for(int x=d;x<=m;x+=d)
            {
                divisors[x].push_back(d);
            }
        }
        vector<int> prev(m+1, 1), curr(m+1);

        prev[0] = 0;

        for(int len = 2; len <= n; len++)
        {
            fill(curr.begin(), curr.end(), 0);
            for(int x = 1; x<= m; x++)
            {
                int ways = 0;
                for(int d : divisors[x])
                {
                    ways += prev[d];
                }

                for(int mult = x+x; mult <= m; mult += x)
                {
                    ways += prev[mult];
                }

                curr[x] = ways;
            }
            swap(prev, curr);
        }
        int ans = 0;
        for(int i=1;i<=m;i++) ans += prev[i];
        return ans;
    };
  public:
    int count(int n, int m) {
        /*vector<vector<int>> ans;
        vector<int> temp;
        solve(n, m, temp, ans);
        return (int)ans.size();*/
        return solveMostOptimal(n,m);
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    Solution s;
    cout<<s.count(n,m)<<endl;
}

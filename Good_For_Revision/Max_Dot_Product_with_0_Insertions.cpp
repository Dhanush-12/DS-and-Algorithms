#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;

/*
    Given two arrays a[] and b[] of positive integers of size n and m respectively, 
    where m ≤ n.  You are allowed to insert zeros anywhere into the second array b so that 
    its length becomes equal to n.

    The dot product of two arrays of equal length n is defined as: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].
    Return the maximum possible dot product of the two arrays.

    Input: a[] = [2, 3, 1, 7, 8], b[] = [3, 6, 7]
    Output: 107
*/

class Solution {
    // Time Complexity : O(2^n)
    // Space Complexity: O(2^n);
    int solveRecursion(int i, int j, int n, int m, vector<int>&a, vector<int>&b)
    {
        if(j == m) return 0;
        if(i == n) return -(int)1e9;

        int not_take = solveRecursion(i+1, j, n, m, a, b);
        int take = a[i]*b[j] + solveRecursion(i+1, j+1, n, m, a, b);

        return max(not_take, take);
    }
    // Time Complexity : O(n*m)
    // Space Complexity : O(n*m)
    int solveMemo(int i, int j, int n, int m, vector<int>&a, vector<int>&b, vector<vector<int>> &dp)
    {
        if(j == m) return 0;
        if(i == n) return -(int)1e9;

        if(dp[i][j] == -1) return dp[i][j];

        int not_take = solveMemo(i+1, j, n, m, a, b, dp);
        int take = a[i]*b[j] + solveMemo(i+1, j+1, n, m, a, b, dp);

        return dp[i][j] = max(not_take, take);
    }
  public:
      int maxDotProductRecursion(vector<int>& a, vector<int>& b) {
        int n = (int)a.size();
        int m = (int)b.size();
        return solveRecursion(0, 0, n, m, a, b);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = (int)a.size();
        int m = (int)b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveMemo(0, 0, n, m, a, b, dp);
    }
    // Time Complexity : O(n*m)
    // Space Complexity : O(n*m)
    int maxDotProductTabulation(vector<int>& a, vector<int>& b) {
        int n = (int)a.size();
        int m = (int)b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<m;i++) dp[n][i] = INT_MIN;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int not_take = dp[i+1][j];
                int take = a[i]*b[j] + dp[i+1][j+1];
                dp[i][j] = max(not_take, take);
            }
        }

        return dp[0][0];
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    Solution s;
    cout<<s.maxDotProductTabulation(a, b)<<endl;
}

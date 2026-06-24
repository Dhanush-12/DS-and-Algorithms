#include <bits/stdc++.h>
using namespace std;

/*
    Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward
    (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell
    (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1]
    is not 0.

    Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path
    exists, return [[-1]].

    Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.

    Input: mat[][] = [[2, 1, 0, 0], [3, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
    Output: [[1, 0, 0, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]

    Input: mat[][] = [[2, 1, 0, 0], [2, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
    Output: [[-1]]
*/

class Solution {
    bool isValidCell(int i, int j ,int n, vector<vector<int>>&arr)
    {
        return (i >= 0 && j >= 0 && i < n && j < n && arr[i][j]);
    }
    bool ratMaze(vector<vector<int>>&arr, vector<vector<int>>&ans, int i, int j, int n, vector<vector<int>>&dp)
    {
        if(!isValidCell(i, j, n, arr)) return false;

        if(i == n-1 && j == n-1)
        {
            ans[i][j] = 1;
            return dp[i][j] = 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        ans[i][j] = 1;

        for(int steps=1;steps<=arr[i][j];steps++)
        {
            if(ratMaze(arr, ans, i, j+steps, n, dp)) return dp[i][j] = 1;
            if(ratMaze(arr, ans, i+steps, j, n, dp)) return dp[i][j] = 1;
        }
        ans[i][j] = 0;

        return dp[i][j] = 0;
    }
  public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if(ratMaze(mat, ans, 0, 0, n, dp)) return ans;
        return {{-1}};
    }
};
int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    Solution s;
    vector<vector<int>> ans = s.shortestDist(arr);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

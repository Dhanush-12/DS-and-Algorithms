#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given a square binary matrix maze[][] containing values 0 and 1, find all
    possible paths for a rat to travel from the top-left cell to the bottom-right cell. The
    rat can move in four directions: up(U), down(D), left(L), and right(R).

    1 represents an open cell through which the rat can move.
    0 represents a blocked cell that cannot be traversed.
    The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

    Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

    Examples:

    Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
    Output: ["DDRDRR", "DRDDRR"]
    Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).
*/
class Solution {
    void solve(int i, int j, int n, string str, vector<string> &ans,
                vector<vector<int>> &arr,  vector<vector<int>> &vis)
    {
        if(i == n-1 && j == n-1)
        {
            ans.push_back(str);
            return;
        }
        vis[i][j] = 1;
        if(i+1 < n && arr[i+1][j] == 1 && !vis[i+1][j]) 
            solve(i+1, j, n, str+'D', ans, arr, vis);
        if(j-1 >= 0 && arr[i][j-1] == 1 && !vis[i][j-1])
            solve(i, j-1, n, str+'L', ans, arr, vis);
        if(j+1 < n && arr[i][j+1] == 1 && !vis[i][j+1])
            solve(i, j+1, n, str+'R', ans, arr, vis);
        if(i-1 >= 0 && arr[i-1][j] == 1 && !vis[i-1][j])
            solve(i-1, j, n, str+'U', ans, arr, vis);
        
        vis[i][j] = 0;
        return;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return {};
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, n, "", ans, maze, vis);
        return ans;
    }
};
int main() 
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    Solution s;
    vector<string> ans = s.ratInMaze(arr);
    for(string &str : ans)
    {
        cout<<str<<endl;
    }
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

    Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

    Input: grid[][] = 
                [['L', 'L', 'W', 'W', 'W'], 
                ['W', 'L', 'W', 'W', 'L'], 
                ['L', 'W', 'W', 'L', 'L'], 
                ['W', 'W', 'W', 'W', 'W'], 
                ['L', 'W', 'L', 'L', 'W']]
    Output: 4

    Input: grid[][] = 
                [['W', 'L', 'L', 'L', 'W', 'W', 'W'], 
                ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
    Output: 2
*/
class Solution {
    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    void bfs(vector<vector<char>> &arr, int i, int j, int n, int m, vector<vector<int>> &vis)
    {
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int currx = it.first;
            int curry = it.second;
            for(int i=0;i<dir.size();i++)
            {
                int newx = currx+dir[i][0];
                int newy = curry+dir[i][1];

                if(newx >= 0 && newx < n && newy >= 0 && newy < m && arr[newx][newy] == 'L' && !vis[newx][newy])
                {
                    vis[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 'W' || vis[i][j]) continue;
                ans++;
                bfs(grid, i, j, n, m, vis);
            }
        }
        return ans;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n, vector<char> (m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.countIslands(arr)<<endl;
}
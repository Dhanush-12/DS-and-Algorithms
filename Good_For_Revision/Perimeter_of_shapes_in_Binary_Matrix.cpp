#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Given a binary matrix mat[][] of size n × m, where each cell contains either 0 or 1,
    find the total perimeter of all figures formed by cells containing 1s. Two cells are considered
    adjacent if they share a common side.

    A single cell containing 1 has a perimeter of 4, whereas two adjacent cells containing 1
    (i.e., 11) together have a perimeter of 6.
*/
class Solution {
    int bfs(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &vis)
    {
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            if(y-1 >= 0 && arr[x][y-1] && !vis[x][y-1])
            {
                q.push({x, y-1});
                vis[x][y-1] = 1;
            }
            else
            {
                if(y-1 < 0 || arr[x][y-1] == 0) ans++;
            }
            if(x-1 >= 0 && arr[x-1][y] && !vis[x-1][y])
            {
                q.push({x-1, y});
                vis[x-1][y] = 1;
            }
            else
            {
                if(x-1 < 0 || arr[x-1][y] == 0) ans++;
            }
            if(y+1 < m && arr[x][y+1] && !vis[x][y+1])
            {
                q.push({x, y+1});
                vis[x][y+1] = 1;
            }
            else
            {
                if(y+1 >= m || arr[x][y+1] == 0) ans++;
            }
            if(x+1 < n && arr[x+1][y] && !vis[x+1][y])
            {
                q.push({x+1, y});
                vis[x+1][y] = 1;
            }
            else
            {
                if(x+1 >= n || arr[x+1][y] == 0) ans++;
            }

        }

        return ans;
    }
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();

        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0 || vis[i][j]) continue;

                ans += bfs(i, j, n, m, mat, vis);
            }
        }
        return ans;
    }
};
int main() 
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    Solution s;
    cout<<s.findPerimeter(arr)<<endl;
}
/*
3 5
0 1 0 0 0
1 1 1 0 0
1 0 0 0 0

2 2
1 0
1 1
*/
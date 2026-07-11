#include<bits/stdc++.h>
using namespace std;
class Solution {
    int ans = -1;
    vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValidCell(int x, int y, int n, int m, vector<vector<int>> &mat)
    {
        return (x >=0 && x < n && y >= 0 && y < m && mat[x][y] == 1);
    }
    void solve(int i, int j, int x, int y, int n, int m, vector<vector<int>> &arr, int path, vector<vector<int>> &vis)
    {
        if(!isValidCell(i, j, n, m, arr) || vis[i][j]) return;
        if(i == x && j == y)
        {
            ans = max(ans, path);
            return;
        }

        vis[i][j] = 1;

        for(auto d : dir) {
            int newx = i+d.first;
            int newy = j+d.second;
            solve(newx, newy, x, y, n, m, arr, path+1, vis);
        }

        vis[i][j] = 0;
    }
  public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        if(mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
        int path = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        solve(xs, ys, xd, yd, n, m, mat, path, vis);
        return ans;
    }
};
int main()
{
    int n,m, xs, ys, xd, yd;
    cin>>n>>m>>xs>>ys>>xd>>yd;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.longestPath(arr, xs, ys, xd, yd)<<endl;
}

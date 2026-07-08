#include<bits/stdc++.h>
using namespace std;

/*
Problem : Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control
          stations monitor the network: Station P covers the top and left boundaries of the grid. Station Q covers the bottom and 
          right boundaries of the grid. A signal can propagate from a tower to one of its neighbouring towers in the four direction
          (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the 
          current tower.

          Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.

          Examples:

          Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
          Output: 7
*/

class Solution {
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isValidCell(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis, queue<pair<int,int>>& q) {
        int n = mat.size();
        int m = mat[0].size();

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (!isValidCell(nx, ny, n, m)) continue;
                if (vis[nx][ny]) continue;

                if (mat[nx][ny] >= mat[x][y]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> qvis(n, vector<int>(m, 0));

        queue<pair<int,int>> qp, qq;

        // Station P: top row + left column
        for (int i = 0; i < n; i++) {
            p[i][0] = 1;
            qp.push({i, 0});
        }

        for (int j = 0; j < m; j++) {
            p[0][j] = 1;
            qp.push({0, j});
        }

        // Station Q: bottom row + right column
        for (int i = 0; i < n; i++) {
            qvis[i][m - 1] = 1;
            qq.push({i, m - 1});
        }

        for (int j = 0; j < m; j++) {
            qvis[n - 1][j] = 1;
            qq.push({n - 1, j});
        }

        bfs(mat, p, qp);
        bfs(mat, qvis, qq);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] && qvis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m, 0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.countCoordinates(arr)<<endl;
}
/*
5 5
1 2 2 3 5
3 2 3 4 4
2 4 5 3 1
6 7 1 4 5
5 1 1 2 4
*/

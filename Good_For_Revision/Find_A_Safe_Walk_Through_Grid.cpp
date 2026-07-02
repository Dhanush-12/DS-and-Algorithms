#include<bits/stdc++.h>
using namespace std;

/*

    Problem: You are given an m x n binary matrix grid and an integer health. You start on the upper-left corner (0, 0) and would 
    like to get to the lower-right corner (m - 1, n - 1). You can move up, down, left, or right from one cell to another adjacent 
    cell as long as your health remains positive. Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

    Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 
    Example 1:

    Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

    Output: true

*/

class Solution {
    vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isCellValid(int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, -1));
        queue<pair<pair<int,int>, int>> q;
        if(grid[0][0] == 1) health -= 1;
        q.push({{0,0}, health});
        best[0][0] = health;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int currh = it.second;
            int currx = it.first.first;
            int curry = it.first.second;
            if(currx == n-1 && curry == m-1)
            {
                return currh > 0;
            }

            for (auto &d : dir)
            {
                int newx = currx + d.first;
                int newy = curry + d.second;

                if (!isCellValid(newx, newy, n, m)) continue;

                int newh = currh - grid[newx][newy];

                if (newh <= 0) continue;

                if (newh > best[newx][newy]) {
                    best[newx][newy] = newh;
                    q.push({{newx, newy}, newh});
                }
            }
        }
        return false;
    }
};
int main()
{
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.findSafeWalk(arr, h)<<endl;
}

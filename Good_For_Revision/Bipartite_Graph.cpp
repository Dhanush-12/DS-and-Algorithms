#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given an undirected graph represented by an adjacency list adj[][], check
    whether the graph is bipartite or not.

    A bipartite graph is a graph whose vertices can be colored using two colors such that
    no two adjacent vertices have the same color. Equivalently, the vertices can be divided
    into two disjoint sets such that:

    Every edge connects a vertex from one set to a vertex in the other set.
    No edge connects two vertices within the same set.
    Examples:

    Input: adj[][] = [[1], [0, 2], [1]]
*/
class Solution {
  public:
    bool isBipartite(vector<vector<int>> &adj) {
        int n = (int)adj.size();
        vector<int> vis(n, -1);

        for(int i=0;i<n;i++)
        {
            if(adj[i].size() == 0 || vis[i] != -1) continue;

            queue<int> q;
            q.push(adj[i][0]);
            vis[adj[i][0]] = 0;

            while(!q.empty())
            {
                int curr = q.front();
                q.pop();

                for(int a : adj[curr])
                {
                    if(vis[a] != -1)
                    {
                        if(vis[a] == vis[curr]) return false;
                        continue;
                    }
                    vis[a] = 1-vis[curr];
                    q.push(a);
                }
            }
        }

        return true;
    }
};
int main() 
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        vector<int> temp(m);
        for(int j=0;j<m;j++) cin>>temp[j];
        arr[i] = temp;
    }
    Solution s;
    cout<<s.isBipartite(arr)<<endl;
}
/*
3
1 1
2 0 2
1 1

3
2 1 2
2 0 2
2 0 1
*/
#include<bits/stdc++.h>
using namespace std;
/*
    Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v]
    denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

    Note: The graph can have multiple component.

    Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
    Output: true
*/
class DSU {
    int n;
    vector<int> parent, sizes;
public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
        sizes.assign(n, 1);
    }
    int findParent(int u)
    {
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }
    void unite(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(sizes[pu] < sizes[pv]) swap(pu, pv);
        parent[pv] = pu;
        sizes[pu] += sizes[pv];
    }
};
class Solution {
  public:
    // Using DSU; TimeComplexity: O(E α(V)) which is essentially O(E) for practical purposes.
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = (int)edges.size();
        DSU dsu(V);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            int pu = dsu.findParent(u);
            int pv = dsu.findParent(v);

            if(pu == pv) return true;

            dsu.unite(u, v);
        }
        return false;
    }
    // Using BFS/DFS; Time Complexity: O(V+E) and Space is same as Time
    bool isCycle(vector<vector<int>>& edges, int V) {
        vector<vector<int>> adj(V);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        vector<int> parent(V, -1);

        for(int i=0;i<V;i++)
        {
            if(vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;
            parent[i] = -1;

            while(!q.empty())
            {
                int curr = q.front();
                q.pop();

                for(int a : adj[curr])
                {
                    if(vis[a])
                    {
                        if(parent[curr] != a) return true;
                        continue;
                    }
                    parent[a] = curr;
                    q.push(a);
                    vis[a] = 1;
                }
            }
        }
        return false;
    }
};
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(m, vector<int>(2));
    for(int i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1];
    Solution s;
    cout<<s.isCycle(arr, n)<<endl;
}
/*
4 4
0 1
0 2
1 2
2 3

4 3
0 1
1 2
2 3
*/

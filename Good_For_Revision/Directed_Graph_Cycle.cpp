#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a directed graph with V vertices numbered from 0 to V - 1 and E directed edges. The graph is represented using a 2D array
    edges[][] of size E, where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v.

    Check whether the graph contains any cycle. Return true if there exists at least one cycle in the graph; otherwise, return false.

    Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]
    Output: true
*/
class Solution {
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
    {
        vis[node] = 1;
        path[node] = 1;
        for(int ch : adj[node])
        {
            if(vis[ch])
            {
                if(path[ch]) return true;
                continue;
            }
            if(dfs(ch, adj, vis, path)) return true;
        }
        path[node] = 0;
        return false;
    }
  public:
    // using DFS
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }
        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for(int i=0;i<V;i++)
        {
            if(vis[i]) continue;
            if(dfs(i, adj, vis, path)) return true;
        }
        return false;
    }
    // Using BFS
    bool isCyclic(vector<vector<int>> &edges, int V) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for(auto it:edges)
        {
            int u  =it[0];
            int v = it[1];

            adj[u].push_back(v);
        }
        for(int u=0;u<V;u++)
        {
            for(int &v : adj[u])
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            cnt++;
            for(int &v : adj[curr])
            {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return cnt != V;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m, vector<int>(2));
    for(int i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1];
    Solution s;
    cout<<s.isCyclic(n, arr)<<endl;
}

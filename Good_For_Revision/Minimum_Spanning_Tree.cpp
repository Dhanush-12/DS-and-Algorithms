#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given a weighted, undirected, and connected graph with V vertices and a 2D array
    edges[][], where each element edges[i] = [u, v, w] represents an edge between vertices u and
    v with weight w, return the sum of the weights of all edges in the graph's Minimum Spanning
    Tree (MST).

    Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
    Output: 4

    Input: V = 2, E = 1, Edges = [[0 1 5]]
    Output: 5 
*/
class DSU {
    int n;
    vector<int> parent;
    vector<int> ranks;
public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
        ranks.assign(n, 0);
    }

    int findParent(int u) {
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(ranks[pu] < ranks[pv]) swap(pu, pv);
        parent[pv] = pu;
        ranks[pu] += ranks[pv];
    }
};
class Solution {
  public:
    // Prims Algorithm
    // Time Complexity: O(E log(E))
    // Space Complexity: O(E)
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);

        for(auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int ans = 0;
        vector<int> vis(V, 0);

        // Storing the parent too just in case if we want to print MST!
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int ,int>>>
                       > pq;
        pq.push({0, {0, -1}});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int u = it.second.first;
            int par = it.second.second;

            if(vis[u]) continue;
            vis[u] = 1;
            ans += w;

            for(auto& [v, weight] : adj[u]) {
                if(vis[v]) continue;

                pq.push({weight, {v, u}});
            }
        }

        return ans;
    }
    // Krushkal's Algorithm
    // Time Complexity: O(m*log(m) + m*4*alpha) where is the m is number of edges
    // Space Complexity: O(V)
    int spanningTree(vector<vector<int>> &edges, int V) {
        DSU dsu(V);

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            if(a[2] == b[2]) return a[0] < b[0];
            return a[2] < b[2];
        });

        int ans = 0;

        for(auto& it : edges) {
            int w = it[2];
            int u = it[0];
            int v = it[1];

            int pu = dsu.findParent(u);
            int pv = dsu.findParent(v);

            if(pu != pv)
            {
                ans += w;
                dsu.unite(u, v); 
            }
        }
        return ans;
    }
};
int main() 
{
    int V, E;
    cin>>V>>E;
    vector<vector<int>> edges(E, vector<int> (3));
    for(int i=0;i<E;i++)
    {
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    Solution s;
    cout<<s.spanningTree(edges, V)<<endl;
}
/*
3 3
0 1 5
1 2 3
0 2 1

2 1
0 1 5

4 5
0 1 6
0 2 3
1 3 9
0 3 1
2 3 6
*/
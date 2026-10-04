#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E
    edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between
    the nodes u and v having w weight.
    Find the shortest distance of all the vertices from the source vertex src, and return an array
    of integers where the ith element denotes the shortest distance between ith node and source
    vertex src.

    Note: The Graph is connected and doesn't contain any negative weight edge.
    It is guaranteed that all the shortest distance will fit in a 32-bit integer.

    Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
    Output: [4, 3, 0]

    Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
    Output: [0, 4, 8, 10, 10]
*/
class Solution {
  public:
    // Using priority_queue slower than using set
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<ll> dist(V, LLONG_MAX);
        dist[src] = 0;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto& [v, w] : adj[u]) {
                ll newDist = d+w;

                if(newDist < dist[v])
                {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        vector<int> ans(V);

        for(int i=0;i<V;i++)
        {
            ans[i] = static_cast<int>(dist[i]);
        }

        return ans;
    }
    // Using set
    vector<int> dijkstra(int V, int src, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> adj(V);

        for(auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<ll> dist(V, LLONG_MAX);
        set<pair<ll,int>> s;

        dist[src] = 0;
        s.insert({0, src});
        
        while(!s.empty()) {
            auto it = *s.begin();
            s.erase(it);

            ll d = it.first;
            int u = it.second;
            if(d != dist[u]) continue;
            
            for(auto& [v, w] : adj[u]) {
                ll newDist = d+w;
                if(newDist < dist[v]) {
                    dist[v] = newDist;
                    s.insert({newDist, v});
                }
            }
        }

        vector<int> ans(V);
        for(int i=0;i<V;i++)
        {
            ans[i] = static_cast<int>(dist[i]);
        }
        return ans;
    }
};
int main() 
{
    int n, m, src;
    cin>>n>>m>>src;
    vector<vector<int>> edges(m, vector<int> (3));
    for(int i=0;i<m;i++) cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    Solution s;
    vector<int> ans = s.dijkstra(n, src, edges);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
3 3 2
0 1 1
1 2 3
0 2 6

5 5 0
0 1 4 
0 2 8
1 4 6
2 3 2
3 4 10
*/
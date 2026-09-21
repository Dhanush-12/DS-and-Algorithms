#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and
    E directed edges represented by a 2D array edges[][], where edges[i] = [u, v] denotes a
    directed edge from vertex u to vertex v, return a topological ordering of all the vertices.

    A topological ordering is a linear ordering of the vertices such that for every directed
    edge u -> v, vertex u appears before vertex v in the ordering.

    Note: As there are multiple Topological orders possible, you may return any of them. If
    your returned Topological sort is correct then the output will be true else false.

    Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
    Output: true
    Explanation: The output true denotes that the order is valid. Few valid Topological orders
    for the given graph are:
    [3, 2, 1, 0]
    [1, 2, 3, 0]
    [2, 3, 1, 0]

    Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]
    Output: true
    Explanation: The output true denotes that the order is valid. Few valid Topological orders
    for the graph are:
    [4, 5, 0, 1, 2, 3]
    [5, 2, 4, 0, 1, 3]
*/
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for(auto it:edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int a : adj[curr]) {
                indegree[a] -= 1;
                if(indegree[a] == 0)
                {
                    q.push(a);
                    ans.push_back(a);
                }
            }
        }

        return ans;
    }
};
int main()
{
    int V, E;
    cin>>V>>E;
    vector<vector<int>> edges(E, vector<int> (2));
    for(int i=0;i<V;i++)
    {
        cin>>edges[i][0]>>edges[i][1];
    }
    Solution s;
    vector<int> ans = s.topoSort(V, edges);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
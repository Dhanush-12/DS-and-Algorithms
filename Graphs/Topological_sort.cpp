#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V+E) and Space Complexity: O(V+E);
// V is the number of vertices and E is the number of edges.
void dfs(int node, int vis[], stack<int>&s,vector<vector<int>>&adj)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
         if(!vis[it]) dfs(it,vis,s,adj);
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<vector<int>>&adj)
{
    int vis[V]={0};
    stack<int>s;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,s,adj);
        }
    }
    vector<int>ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>>edges(E,vector<int>(2));
    for(int i=0;i<E;i++)
    {
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>adj(V);
    for(auto &it:edges)
    {
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
    }
    vector<int>ans=topoSort(V,adj);
    cout<<"Topological sort for the given graph is: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

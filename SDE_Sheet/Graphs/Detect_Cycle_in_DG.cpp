#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>&adj, int vis[], int pathVis[])
{
    vis[node]=1;
    pathVis[node]=1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,vis,pathVis)==true)
            {
                return true;
            }
        }
        else if(pathVis[it]) return true;
    }
    pathVis[node]=0;
    return false;
}
// Time Complexity: O(V+E) and Space Complexity: O(V+E);
// V is the number of vertices and E is the number of edges.
bool isCyclic(int V , vector<vector<int>>&adj)
{
    int vis[V]={0};
    int pathVis[V]={0};

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis,pathVis) == true) return true;
        }
    }
    return false;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>>edges(E,vector<int>(2,0));
    for(int i=0;i<E;i++)
    {
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    if(isCyclic(V,adj))
    {
        cout<<"The graph contains cycle"<<endl;
    }
    else
    {
        cout<<"The graph does not contain cycle"<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V*E) and Space Complexity: O(V);
// V is the number of vertices and E is the number of edges in the graph.
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int>dist(V,1e8);
    dist[src]=0;
    for(int i=0;i<V-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u] != 1e8 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    // Nth relaxation to check the negitive cycle
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u] != 1e8 && dist[u]+wt<dist[v])
        {
            return {-1};
        }
    }

    return dist;
}
int main()
{
    int V,src;
    cin>>V>>src;
    vector<vector<int>>arr(V,vector<int>(3,0));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<int>ans=bellmanFord(V,arr,src);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

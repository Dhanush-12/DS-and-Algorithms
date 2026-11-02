#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem : Given a directed graph with V vertices labeled from 0 to V - 1, represented by an
    adjacency list adj, find number of strongly connected components (SCCs) in the graph.

    A strongly connected component is a maximal set of vertices such that every vertex is reachable
    from every other vertex in the same component.

    Examples:

    Input: adj[][] = [[1], [2], [0, 3], [4], [3, 5], []]
    Output: 3
    Explanation: The strongly connected components are: {0, 1, 2},{3, 4} and {5}. Therefore, the
    total number of SCCs is 3.
*/
class Solution {
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(vis[it]) continue;
            dfs(it, vis, adj, st);
        }

        st.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjt)
    {
        vis[node] = 1;
        for(auto it : adjt[node])
        {
            if(vis[it]) continue;
            dfs2(it, vis, adjt);
        }
    }
  public:
    int countSCC(vector<vector<int>>& adj) {
        int V = (int)adj.size();
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(vis[i]) continue;
            dfs(i, vis, adj, st);
        }

        vector<vector<int>> adjt(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                adjt[it].push_back(i);
            }
        }

        vis.assign(V, 0);
        int ans = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(vis[node]) continue;
            ans++;
            dfs2(node, vis, adjt);
        }
        return ans;
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
        vector<int> ls(m);
        for(int j=0;j<m;j++)
        {
            cin>>ls[j];
        }
        arr[i] = ls;
    }
    Solution s;
    cout<<s.countSCC(arr)<<endl;
}
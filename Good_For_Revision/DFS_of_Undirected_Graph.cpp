#include<bits/stdc++.h>
using namespace std;
/*
   Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents
   the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices
   from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

   Note: Do traverse in the same order as they are in the given adjacency list.

   Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
   Output: [0, 2, 4, 3, 1]

   Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
   Output: [0, 1, 2, 3, 4]
*/
class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans)
    {
       vis[node] = 1;
       ans.push_back(node);

       for(int ch : adj[node])
       {
          if(vis[ch]) continue;
          dfs(ch, adj, vis, ans);
       }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = (int)adj.size();
        vector<int> ans;
        vector<int> vis(n);
        dfs(0, adj, vis, ans);
        return ans;
    }
};
int main()
{
   int n;
   cin>>n;
   vector<vector<int>> adj;
   for(int i=0;i<n;i++)
   {
      int m;
      cin>>m;
      vector<int> arr;
      for(int j=0;j<m;j++)
      {
         int a;
         cin>>a;
         arr.push_back(a);
      }
      adj.push_back(arr);
   }
   Solution s;
   vector<int> ans = s.dfs(adj);
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   cout<<endl;
}

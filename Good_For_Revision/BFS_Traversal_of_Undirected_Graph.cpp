#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i]
    represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0,
    visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the
    graph.

    Note: Do traverse in the same order as they are in the given adjacency list.

    Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
    Output: [0, 2, 3, 1, 4]

    Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
    Output: [0, 1, 2, 3, 4]
*/
class Solution {
  public:
    // Time Complexity: O(V+E)
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = (int)adj.size();
        vector<int> ans;
        queue<int> q;
        q.push(0);
        ans.push_back(0);

        vector<int> vis(n, 0);
        vis[0] = 1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int ch : adj[curr])
            {
                if(vis[ch]) continue;
                vis[ch] = 1;
                ans.push_back(ch);
                q.push(ch);
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        vector<int> arr(m);
        for(int j=0;j<m;j++) cin>>arr[j];
        adj[i] = arr;
    }
    Solution s;
    vector<int> ans = s.bfs(adj);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

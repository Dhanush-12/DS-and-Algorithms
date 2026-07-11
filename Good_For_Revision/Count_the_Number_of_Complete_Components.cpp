#include<bits/stdc++.h>
using namespace std;

/*

    Problem : You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a
    2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

    Return the number of complete connected components of the graph. A connected component is a subgraph of a graph in which there
    exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

    A connected component is said to be complete if there exists an edge between every pair of its vertices.

    Example 1:
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    Output: 3
    Explanation: From the picture above, one can see that all of the components of this graph are complete.

*/

class DSU {
    int n;
    vector<int> parent, sizes;
public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        sizes.assign(n, 1);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int findParent(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(sizes[pu] < sizes[pv]) swap(pu, pv);
        parent[pv] = pu;
        sizes[pu] += sizes[pv];
    }

    int findSize(int u) {
        return sizes[u];
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_set<int> s, covered;
        for(auto it : edges)
        {
            dsu.unite(it[0], it[1]);
            s.insert(it[0]);
            s.insert(it[1]);
        }
        int ans = (n-(int)s.size());
        unordered_map<int,int> parent;
        for(int i=0;i<n;i++) parent[i] = dsu.findParent(i);
        vector<int> h(n, 0);
        for(auto it:edges)
        {
            h[parent[it[0]]]++;
        }
        for(int i=0;i<n;i++)
        {
            int currParent = parent[i];
            int currSize = dsu.findSize(currParent);
            if(covered.count(currParent) || currSize == 1) continue;
            if((currSize*(currSize-1))/2 == h[currParent]) ans++;
            covered.insert(currParent);
        }
        return ans;
    }
};
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(m, vector<int>(2));
    for(int i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1];
    Solution s;
    cout<<s.countCompleteComponents(n, arr)<<endl;
}
/*
6 4
0 1
0 2
1 2
3 4

4 3
2 0
3 1
3 2
*/

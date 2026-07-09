#include<bits/stdc++.h>
using namespace std;

/*
    Problem : You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1. You are also given
    an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff. An undirected edge exists between
    nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
    You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between
    nodes ui and vi. Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith
    query and false otherwise.

    Example 1:

    Input: n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]

    Output: [true,false]

    Explanation:

    Query [0,0]: Node 0 has a trivial path to itself.
    Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |1 - 3| = 2, which is greater than maxDiff.
    Thus, the final answer after processing all the queries is [true, false].
    Example 2:

    Input: n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]

    Output: [false,false,true,true]
*/

class DSU {
    int n;
    vector<int> parent,sizes;
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
};
class Solution {
public:
    // Solution using DSU but not so efficient and not necessary for this specific problem
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        DSU dsu(n);
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1] <= maxDiff)
            {
                dsu.unite(i-1, i);
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int p = dsu.findParent(i);
            mp[i] = p;
        }
        for(auto q : queries) {
            int u = q[0];
            int v = q[1];
            if(mp[u] == mp[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
    // Better and Optimal Approach
    vector<bool> pathExistenceQueries(vector<int>& nums, int n, int maxDiff, vector<vector<int>>& queries) {
        vector<int> groups(n, 0);
        vector<bool> ans;
        groups[0] = 1;
        int curr = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1] > maxDiff)
            {
                curr++;
            }
            groups[i] = curr;
        }
        for(auto q : queries) {
            int u = q[0];
            int v = q[1];
            if(groups[u] == groups[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
int main()
{
    int n,q,maxDiff;
    cin>>n>>q>>maxDiff;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i=0;i<q;i++) cin>>queries[i][0]>>queries[i][1];
    Solution s;
    vector<bool> ans = s.pathExistenceQueries(n, nums, maxDiff, queries);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

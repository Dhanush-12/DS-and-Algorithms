#include<bits/stdc++.h>
using namespace std;

/*
    Porblem : Given a tree with n nodes numbered from 0 to n - 1, rooted at node 0 and an array
    arr[], where arr[i] represents the parent of node i. For the root node, arr[0] = -1.

    Also given a 2D array queries[][] of size q × 2, where each query is of the form [u, k].

    For each query, find the k-th ancestor of node u, i.e., the node obtained after moving k
    times from u to its parent. If the k-th ancestor does not exist, return -1.

    Return an array containing the answer for each query in the same order.

    Examples:

    Input: arr[] = [-1, 0, 0, 1, 1], queries[][] = [[4, 1], [3, 2], [4, 3]] Output: [1, 0, -1]
*/

class Solution {
  public:
    vector<int> kthAncestorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = (int)arr.size();
        int LOG = 20;
        vector<int> ans;
        vector<vector<int>> up(n, vector<int>(LOG, -1));
        for(int i=0;i<n;i++) up[i][0] = arr[i];

        for(int j=1;j<LOG;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(up[i][j-1] != -1)
                {
                    up[i][j] = up[ up[i][j-1] ][j-1];
                }
            }
        }
        for(auto it : queries)
        {
            int u = it[0];
            int k = it[1];
            int node = u;
            for(int j=0;j<LOG;j++)
            {
                if(node == -1) break;
                if(k & (1 << j)) node = up[node][j];
            }
            ans.push_back(node);
        }
        return ans;
    }
};
int main()
{
    int n, q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i=0;i<q;i++) cin>>queries[i][0]>>queries[i][1];
    Solution s;
    vector<int> ans = s.kthAncestorQueries(arr, queries);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
5 3
-1 0 0 1 1
4 1
3 2
4 3

8 4
-1 0 1 0 1 1 3 3
5 1
5 2
2 2
7 2

2 4
-1 0
1 2
1 1
1 2
0 1
*/

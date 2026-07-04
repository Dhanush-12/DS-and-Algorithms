#include<bits/stdc++.h>
using namespace std;

/*

    2492. Minimum Score of a Path Between Two Cities: You are given a positive integer n representing n cities numbered from 1 to n.
          You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road
          between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected. The score of
          a path between two cities is defined as the minimum distance of a road in this path.

          Return the minimum possible score of a path between cities 1 and n.

          Note:A path is a sequence of roads between two cities. It is allowed for a path to contain the same road multiple times,
               and you can visit cities 1 and n multiple times along the path. The test cases are generated such that there is at
               least one path between 1 and n.


          Example 1:
          Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
          Output: 5
          Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
          It can be shown that no other path has less score.

*/
/* 
Complexity:

Time: O(E α(n))
Space: O(n)

Where α(n) is almost constant.
*/
class DSU {
    int n;
    vector<int> parent, size;
    public:
    DSU(int n) {
        this->n = n;
        parent.resize(n+1);
        size.assign(n+1, 1);

        for(int i=1;i<=n;i++) parent[i] = i;
    }

    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }

};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);
        for(auto& road : roads) {
            dsu.unite(road[0], road[1]);
        }

        int comp = dsu.find(1);
        int ans = INT_MAX;

        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            if(dsu.find(u) == comp) {
                ans = min(ans, w);
            }
        }
        return ans;
    }
};
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(m, vector<int>(3));
    for(int i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    Solution s;
    cout<<s.minScore(n, arr)<<endl;
}

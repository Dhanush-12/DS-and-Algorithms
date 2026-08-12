#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;
/*
    In a kingdom of n cities(0 to n - 1), connected by n - 1 roads, there is exactly one path between any two cities. The kingdom
    depends on this network, where every city is accessible from every other city. However, the evil mayor, decides to shut down one
    city, causing the roads connected to it to be severed.

    Given an array roads[][], such that roads[i] = [u, v] denoting that there is a road connecting city u with city v, the task is to
    determine the maximum number of pairs of cities that will become disconnected if the mayor shuts down just one city.

    Note:  When calculating the number of disconnected cities, the shutdown city itself is not counted.

    Examples:

    Input: n = 5, roads[][] = [[0, 1], [1, 2], [1, 3], [1, 4]]
    Output: 6
    Explanation: The mayor can shut down city 1, resulting in following pairs of cities being disconnected: [0, 2], [0, 3], [0, 4], [2, 3], [2, 4] and [3, 4].
*/
class Solution {
  public:
    long long maxCities(vector<vector<int>> &roads, int n) {
        vector<vector<int>> adj(n);
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> parent(n, -1);
        vector<int> subtree(n, 1);
        vector<int> order;

        order.reserve(n);

        stack<int> st;
        st.push(0);
        parent[0] = -2;

        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            order.push_back(u);

            for(int v : adj[u])
            {
                if(v == parent[u]) continue;

                parent[v] = u;
                st.push(v);
            }
        }

        for(int i=n-1;i>0;i--)
        {
            int u = order[i];
            subtree[parent[u]] += subtree[u];
        }

        long long ans = 0;

        for(int u=0;u<n;u++)
        {
            long long sum = 0;
            long long pairs = 0;

            for(int v : adj[u])
            {
                long long sz;

                if(parent[v] == u)
                {
                    sz = subtree[v];
                }
                else
                {
                    sz = n-subtree[u];
                }

                pairs += sum*sz;
                sum += sz;
            }
            ans = max(ans, pairs);
        }
        return ans;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m, vector<int>(2));
    for(int i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1];
    Solution s;
    cout<<s.maxCities(arr, n)<<endl;
}
/*
5 4
0 1
1 2
1 3
1 4

3 2
0 1
1 2

7 6
4 6
0 2
2 5
6 2
2 3
2 1
*/

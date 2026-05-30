#include<bits/stdc++.h>
using namespace std;

/* Question: 3161(Leetcode). Block Placement Queries Hard

There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

You are given a 2D array queries, which contains two types of queries:

For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.



Example 1:

Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]

Explanation:



For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

Example 2:

Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]

Explanation:



Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.


Constraints:

1 <= queries.length <= 15 * 104
2 <= queries[i].length <= 3
1 <= queries[i][0] <= 2
1 <= x, sz <= min(5 * 104, 3 * queries.length)
The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
The input is generated such that there is at least one query of type 2.

*/

class FenwickTree
{
public:
    vector<int> bit;
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit = vector<int>(n+1, 0);
    }

    void add(int id, int val)
    {
        while(id <= n)
        {
            bit[id] = max(bit[id], val);
            id += (id & -id);
        }
    }

    int query(int id)
    {
        int maxi = 0;
        while(id > 0)
        {
            maxi = max(maxi, bit[id]);
            id -= (id & -id);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = min(5*10000, 3*(int)queries.size()) + 1;
        set<int> obs;
        obs.insert(0);
        obs.insert(n);

        FenwickTree ft(n);
        for(auto q : queries)
        {
            int type = q[0];
            if(type == 1)
            {
                int x = q[1];
                obs.insert(x);
            }
        }

        for(auto it = obs.begin(); it != obs.end(); it++)
        {
            if(it == obs.begin()) continue;
            auto prevIt = prev(it);
            int x = *it, gapSize = (*it-*prevIt);
            ft.add(x, gapSize);
        }

        vector<bool> ans;
        for(int i=queries.size()-1; i>=0; i--)
        {
            int type = queries[i][0];
            if(type == 1)
            {
                int x = queries[i][1];
                auto it = obs.find(x);
                auto pre = prev(it);
                auto nxt = next(it);
                obs.erase(it);
                ft.add(*nxt, *nxt-*pre);
            }
            else
            {
                int x = queries[i][1], sz = queries[i][2];
                auto nxt = obs.upper_bound(x);
                auto pre = prev(nxt);

                int mxGap = max(ft.query(*pre), x-*pre);
                ans.push_back(mxGap >= sz);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> q(n);
    for(int i=0;i<n;i++)
    {
        int qu;
        cin>>qu;
        if(qu == 1)
        {
            int x;
            cin>>x;
            q[i]={1, x};
        }
        else
        {
            int x, b;
            cin>>x>>b;
            q[i]={2, x, b};
        }
    }
    Solution s;
    vector<bool> ans = s.getResults(q);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

/*
4
1 2
2 3 3
2 3 1
2 2 2

5
1 7
2 7 6
1 2
2 7 5
2 7 6
*/

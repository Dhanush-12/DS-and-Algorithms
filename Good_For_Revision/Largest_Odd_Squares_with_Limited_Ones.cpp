#include<bits/stdc++.h>
using namespace std;
/*
    Porblem : Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries queries[][]. Each query contains
    coordinates [i, j] of the center of a square.

    For every query, find the side length of the largest odd-sized square centered at cell (i, j) such that the square contains at
    most k ones. A square centered at (i, j) expands outward symmetrically in all four directions by the same number of cells, so
    its side length is always odd. Note: If no odd-sized square centered at the given cell satisfies the condition of containing at
    most k ones, return -1 for that query.

    Examples:

    Input: mat[][] = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]], queries[][] = [[1, 2]], k = 9
    Output: [3]
*/
class Solution {
public:

    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();

        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pref[i+1][j+1] = mat[i][j]+pref[i+1][j]+pref[i][j+1]-pref[i][j];
            }
        }
        auto getSum = [&](int r1, int c1, int r2, int c2)
        {
            return pref[r2+1][c2+1]-pref[r1][c2+1]-pref[r2+1][c1]+pref[r1][c1];
        };
        vector<int> ans;
        for(auto it:queries)
        {
            int r = it[0];
            int c = it[1];

            int maxiRadius = min({r, c, n-1-r, m-1-c});

            int low = 0;
            int high = maxiRadius;
            int best = -1;
            while(low <= high)
            {
                int mid = low + (high-low)/2;
                int r1 = r-mid;
                int r2 = r+mid;
                int c1 = c-mid;
                int c2 = c+mid;

                int ones = getSum(r1,c1,r2,c2);

                if(ones <= k) {
                    best = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            if(best == -1) ans.push_back(-1);
            else ans.push_back(2*best + 1);
        }
        return ans;
    }
};
int main()
{
    int n,m,q,k;
    cin>>n>>m>>q>>k;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i=0;i<q;i++) cin>>queries[i][0]>>queries[i][1];
    Solution s;
    vector<int> ans = s.largestSquare(arr, queries, k);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
4 5 1 9
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
1 2

3 3 2 9
1 1 1
1 1 1
1 1 1
1 1
2 2

4 4 3 6
0 0 0 0
0 1 1 0
1 1 0 1
0 1 1 1
2 2
1 2
0 2
*/

#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a 2D binary matrix mat[][], where each cell contains either 0 or 1.
    Find the maximum area of a rectangle that can be formed using only 1's within the
    matrix.

    Input: mat[][] = [[0, 1, 1, 0], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 0, 0]]
    Output: 8

    Input: mat[][] = [[0, 1, 1], [1, 1, 1], [0, 1, 1]]
    Output: 6
*/
class Solution {
    int solve(vector<int> &h, int m)
    {
        stack<int> s;
        int ans = 0;
        for(int i=0;i<=m;i++)
        {
            int hh = (i == m) ? 0 : h[i];
            while(!s.empty() && hh < h[s.top()])
            {
                int currh = h[s.top()];
                s.pop();
                int w = (s.empty() ? i : i-s.top()-1);
                ans = max(ans, currh*w);
            }
            s.push(i);
        }
        return ans;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        vector<int> h(m, 0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                h[j] = (mat[i][j] == 0) ? 0 : h[j]+1;
            }
            ans = max(ans, solve(h, m));
        }
        return ans;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.maxArea(arr)<<endl;
}
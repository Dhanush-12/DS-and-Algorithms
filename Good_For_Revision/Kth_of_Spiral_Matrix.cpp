#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given a matrix mat[][] and a number k, find the k-th element obtained while traversing
    the matrix in spiral order.

    Note: Spiral traversal follows a pattern where we move left to right on the top row, top to
    bottom on the last column, right to left on the bottom row, and bottom to top on the first
    column, repeating this process for the inner layers until all elements are visited.

    Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], k = 10
    Output: 13

    Input: mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 4
    Output: 6
*/
class Solution {
  public:
    int findK(vector<vector<int>> &mat, int k) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        int rs = 0, re = n-1, cs = 0, ce = m-1;
        vector<int> arr;
        while(rs <= re && cs <= ce)
        {
            for(int i=cs;i<=ce;i++)
            {
                arr.push_back(mat[rs][i]);
            }
            rs++;
            for(int i=rs;i<=re;i++)
            {
                arr.push_back(mat[i][ce]);
            }
            ce--;
            for(int i=ce;i>=cs;i--)
            {
                arr.push_back(mat[re][i]);
            }
            re--;
            for(int i=re;i>=rs;i--)
            {
                arr.push_back(mat[i][cs]);
            }
            cs++;
        }
        return arr[k-1];
    }
};
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.findK(arr, k)<<endl;
}
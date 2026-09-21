#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Consider a party being organized by some people. A celebrity is a person who is
    known to all but does not know anyone at the party. 

    A square matrix mat[][] of size n * n is used to represent people at the party such that if
    an element of row i and column j is set to 1 it means ith person knows jth person. You need
    to return index of the celebrity in the party. If the celebrity does not exist, return -1.
    Note: Follow 0-based indexing.

    Input: mat[][] = [[1, 1, 0],
                    [0, 1, 0],
                    [0, 1, 1]]
    Output: 1

    Input: mat[][] = [[1, 1], 
                    [1, 1]]
    Output: -1

    Input: mat[][] = [[1, 1], 
                    [1, 1]]
    Output: -1
*/
class Solution {
  public:
    // Time Complexity: O(n^2);
    // Space Complexity: O(n);
    int celebrity(int n, vector<vector<int>>& mat) {
        vector<int> vis(n, 1);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) continue;
            for(int j=0;j<n;j++)
            {
                if(i == j) continue;
                if(mat[i][j] == 1) vis[i] = 0;
                else vis[j] = 0;
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            {
                if(ans != -1) return -1;
                ans = i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i == ans) continue;
            if(mat[i][ans] == 0) return -1;
        }
        return ans;
    }
    // Best Solution
    // Time Complexity: O(n);
    // Space Complexity: O(1);
    int celebrity(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        int candidate = 0;
        
        for(int i=1;i<n;i++)
        {
            if(mat[candidate][i] == 1) candidate = i;
        }

        for(int i=0;i<n;i++)
        {
            if(i == candidate) continue;

            if(mat[candidate][i] == 1 || mat[i][candidate] == 0) return -1;
        }
        
        return candidate;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.celebrity(arr)<<endl;
}
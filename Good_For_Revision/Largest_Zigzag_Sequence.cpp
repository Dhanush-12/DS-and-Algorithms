#include<bits/stdc++.h>
using namespace std;
/*
    Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends at the
    bottom. Two consecutive elements of sequence cannot belong to the same column.

    Return the maximum sum of such a zigzag sequence.

    Examples:

    Input: mat[][] = [[3, 1, 2], [4, 8, 5], [6, 9, 7]]
    Output: 18
*/
class Solution {
  public:
      // Time Complexity: O(n*n*n)
      // Space Complexity: O(n*n)
      int zigzagSequence(int n, vector<vector<int>>& mat) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++) dp[n-1][i] = mat[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(j == k) continue;
                    dp[i][j] = max(dp[i][j], mat[i][j] + dp[i+1][k]);
                }
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
    // Time Complexity : O(n*n*n);
    // Space Complexity: O(n)
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        vector<int> prev(n, 0), curr(n, 0);
        for(int i=0;i<n;i++) prev[i] = mat[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(j == k) continue;
                    curr[j] = max(curr[j], mat[i][j] + prev[k]);
                }
            }
            swap(prev, curr);
        }
        return *max_element(prev.begin(), prev.end());
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.zigzagSequence(arr)<<endl;
}
/*
3
3 1 2
4 8 5
6 9 7

3
1 2 4
3 9 6
11 3 15

3
1 5 3
7 2 4
6 8 9
*/

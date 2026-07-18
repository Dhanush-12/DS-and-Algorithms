#include<bits/stdc++.h>
using namespace std;
/*
    Problem : Given a matrix of 0s and 1s and an integer k, divide the matrix into k pieces such that each piece has at least one 1 in it. A cut can be made in the following way:

    Choose a direction: vertical or horizontal.
    Choose an index to cut the matrix into two pieces.
    If the cut is horizontal, only the bottom part can be cut further.
    If the cut is vertical, only the right part can be cut further.
    Return the number of different ways to divide the matrix modulo 1e9 + 7.

    Examples:

    Input: matrix = [[1, 0, 0], [1, 1, 1], [0, 0,0]], k = 3
    Output: 3
*/
class Solution {
  public:
    int findWays(vector<vector<int>>& matrix, int k) {
        const int mod = 1e9 + 7;
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        vector<vector<int>> ones(n+1, vector<int>(m+1, 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                ones[i][j] = matrix[i][j]+ones[i+1][j]+ones[i][j+1]-ones[i+1][j+1];
            }
        }
        if(ones[0][0] < k) return 0;
        vector<vector<int>> firstDown(n, vector<int> (m, n));
        for(int j=0;j<m;j++)
        {
            for(int i=n-2;i>=0;i--)
            {
                int currRowOnes = ones[i][j]-ones[i+1][j];
                if(currRowOnes > 0)
                {
                    firstDown[i][j] = i+1;
                }
                else
                {
                    firstDown[i][j] = firstDown[i+1][j];
                }
            }
        }
        vector<vector<int>> firstRight(n, vector<int>(m, m));
        for(int i=0;i<n;i++)
        {
            for(int j=m-2;j>=0;j--)
            {
                int currColOnes = ones[i][j] - ones[i][j+1];
                if(currColOnes > 0)
                {
                    firstRight[i][j] = j+1;
                }
                else
                {
                    firstRight[i][j] = firstRight[i][j+1];
                }
            }
        }

        vector<vector<int>> previous(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) previous[i][j] = (ones[i][j] > 0);
        }
        for(int pieces = 2; pieces <= k; pieces++)
        {
            vector<vector<int>> downSum(n+1, vector<int>(m, 0));
            for(int j=0;j<m;j++)
            {
                for(int i=n-1;i>=0;i--)
                {
                    downSum[i][j] = (previous[i][j] + downSum[i+1][j]) % mod;
                }
            }

            vector<vector<int>> rightSum(n, vector<int>(m+1, 0));
            for(int i=0;i<n;i++)
            {
                for(int j=m-1;j>=0;j--)
                {
                    rightSum[i][j] = (previous[i][j] + rightSum[i][j+1]) % mod;
                }
            }
            vector<vector<int>> current(n, vector<int>(m, 0));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(ones[i][j] < pieces) continue;
                    long long ways = 0;
                    int nextRow = firstDown[i][j];
                    if(nextRow < n)
                    {
                        ways += downSum[nextRow][j];
                    }
                    int nextCol = firstRight[i][j];
                    if(nextCol < m)
                    {
                        ways += rightSum[i][nextCol];
                    }

                    current[i][j] = ways%mod;
                }
            }
            previous = move(current);
        }
        return previous[0][0];
    }
};
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.findWays(arr, k)<<endl;
}
/*
3 3 3
1 0 0
1 1 1
0 0 0
*/

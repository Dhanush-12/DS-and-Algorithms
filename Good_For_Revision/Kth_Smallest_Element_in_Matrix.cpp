#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

    Input: mat[][] = 
                    [[16, 28, 60, 64], k = 3
                    [22, 41, 63, 91],
                    [27, 50, 87, 93],
                    [36, 78, 87, 94]]
    Output: 27
    Explanation: 27 is the 3rd smallest element.

    Input: mat[][] = 
                [[10, 20, 30, 40], k = 7
                [15, 25, 35, 45],
                [24, 29, 37, 48],
                [32, 33, 39, 50]] 
    Output: 30
    Explanation: 30 is the 7th smallest element.
*/
class Solution {
  public:
    // Using Priority Queue
    // Time Complexity: O(n + k*log(n))
    // Auxiliary Space: O(n)
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = (int)mat.size();

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        // Insert the first element from each row
        for(int i=0;i<n;i++)
        {
            pq.push({mat[i][0], i, 0});
        }

        int ans = -1;
        
        while(k--)
        {
            auto [val, r, c] = pq.top();
            pq.pop();

            ans = val;

            if(c+1 < n) {
                pq.push({mat[r][c+1], r, c+1});
            }
        }
        return ans;
    }
    // Time Complexity: O(n * log(max-min+1))
    // Space Complexity: O(1)
    int kthSmallest(int k, vector<vector<int>> &mat) {
        int n = (int)mat.size();

        int low = mat[0][0];
        int high = mat[n-1][n-1];
        int mid;

        while(low < high)
        {
            mid = low + (high - low) / 2;

            int count = 0;
            int row = n-1;
            int col = 0;

            while(row >= 0 && col < n) {
                if(mat[row][col] <= mid) {
                    count += row+1;
                    col++;
                }
                else row--;
            }
            if(count < k) low = mid+1;
            else high = mid;
        }
        return low;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n, vector<int> (n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    Solution s;
    cout<<s.kthSmallest(k, arr)<<endl;
}
/*
4 3
16 28 60 64
22 41 63 91
27 50 87 93
36 78 87 94

4 7
10 20 30 40
15 25 35 45
24 29 37 48
32 33 39 50
*/
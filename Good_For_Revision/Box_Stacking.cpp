#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given three arrays height[], width[], and length[] of size n, where height[i],
    width[i], and length[i] represent the dimensions of the ith box, find the maximum possible
    height of a stack formed using these boxes.

    A box can be rotated so that any of its dimensions becomes its height.
    A box can be placed on top of another only if both dimensions of its base are strictly
    smaller than those of the box below.

    Multiple instances of the same box can be used.
    Examples:

    Input: height[] = [4, 1, 4, 10], width[] = [6, 2, 5, 12], length[] = [7, 3, 6, 32]
    Output: 60

    Input: height[] = [1, 4, 3], width[] = [2, 5, 4], length[] = [3, 6, 1]
    Output: 15
*/
class Solution {
    // Time Complexity: O(n* maxil * maxib);
    // Space Complexity: O(n* maxil * maxib);
    int solve(int ind, int n, vector<array<int, 3>> &arr, int l, int b, vector<vector<vector<int>>> &dp)
    {
        if(ind == n) return 0;

        int li = l+1, bi = b+1;

        if(dp[ind][li][bi] != -1) return dp[ind][li][bi];

        int take = 0, not_take = 0;
        int currl = arr[ind][0];
        int currb = arr[ind][1];
        int currh = arr[ind][2];

        if((l == -1 && b == -1) || (currl < l && currb < b))
        {
            take = currh + solve(ind+1, n, arr, currl, currb, dp);
        }
        not_take = solve(ind+1, n, arr, l, b, dp);

        return dp[ind][li][bi] = max(take, not_take);
    }
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = (int)height.size();
        int ans = 0;
        vector<array<int, 3>> boxes;
        for(int i=0;i<n;i++)
        {
            int a = height[i];
            int b = width[i];
            int c = length[i];

            boxes.push_back({max(b, c), min(b, c), a});
            boxes.push_back({max(a, c), min(a, c), b});
            boxes.push_back({max(a, b), min(a, b), c});
        }
        sort(boxes.rbegin(), boxes.rend());
        int m = (int)boxes.size();
        int maxil = -1, maxib = -1;
        for(auto &box : boxes)
        {
            maxil = max(maxil, box[0]);
            maxib = max(maxib, box[1]);
        }
        // vector<vector<vector<int>>> dp(m, vector<vector<int>> (maxil+2, vector<int> (maxib+2, -1)));
        // return solve(0, m, boxes, -1, -1, dp);


        // Tabulation method: O(n^2), suitable for given constraints
        vector<int> dp(m);

        int ans = 0;
        for(int i=0;i<m;i++)
        {
            dp[i] = boxes[i][2];
            for(int j=0;j<i;j++)
            {
                if(boxes[j][0] > boxes[i][0] && boxes[j][1] > boxes[i][1]) {
                    dp[i] = max(dp[i], boxes[i][2]+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> height(n), width(n), length(n);
    for(int i=0;i<n;i++) cin>>height[i];
    for(int i=0;i<n;i++) cin>>width[i];
    for(int i=0;i<n;i++) cin>>length[i];
    Solution s;
    cout<<s.maxHeight(height, width, length)<<endl;
}
/*
4
4 1 4 10
6 2 5 12
7 3 6 32

3
1 4 3
2 5 4
3 6 1
*/
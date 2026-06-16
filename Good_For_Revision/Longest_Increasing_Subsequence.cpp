#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Time complexity: O(n^2)
    // Space Complexity: O(1)
    int longestIncreasingSubsequence(int n, vector<int>&arr) {
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(arr[j] < arr[i])
                {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    // Time complexity: O(n*log(n))
    // Space Complexity: O(n)
    int longestIncreasingSubsequence(vector<int> &arr)
    {
        int n = (int)arr.size();
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.longestIncreasingSubsequence(n, arr)<<endl;
    cout<<s.longestIncreasingSubsequence(arr)<<endl;
}

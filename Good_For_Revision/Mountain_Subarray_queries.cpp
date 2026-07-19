#include<bits/stdc++.h>
using namespace std;

/*
    Problem : Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

    Elements of a Mountain subarray are first non-decreasing and then non-increasing.
    A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.
    Examples:

    Input: arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
    Output: [true, false]
*/

class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = (int)arr.size();
        int m = (int)queries.size();
        vector<int> up(n), down(n);
        up[n-1] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] <= arr[i+1]) up[i] = up[i+1];
            else up[i] = i;
        }
        down[0] = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] <= arr[i-1]) down[i] = down[i-1];
            else down[i] = i;
        }
        vector<bool> ans;
        for(const auto& q : queries)
        {
            int l = q[0];
            int r = q[1];
            ans.push_back(down[r] <= up[l]);
        }
        return ans;
    }
};
int main()
{
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> queries;
    int l,r;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        queries.push_back({l, r});
    }
    Solution s;
    vector<bool> ans = s.processQueries(arr, queries);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;

/*

    Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

    Note: After skipping the element, the subarray must still be non-empty.

    Examples:

    Input: arr[] = [1, 2, 3, -4, 5]
    Output: 11

*/

class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = (int)arr.size();
        int noDel = arr[0];
        int oneDel = 0;
        int ans = arr[0];
        for(int i=1;i<n;i++)
        {
            oneDel = max(oneDel + arr[i], noDel);
            noDel = max(noDel+arr[i], arr[i]);

            ans = max(ans, max(noDel, oneDel));
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.maxSumSubarray(arr)<<endl;
}

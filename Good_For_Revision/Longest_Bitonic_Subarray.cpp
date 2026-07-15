#include<bits/stdc++.h>
using namespace std;

/*
    Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic subarray.

    A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease.
    Formally, there exists and index k (where i <= k <= j) such that:

    arr[i] <= arr[i+1] <= . . . <= arr[k] 
    arr[k] >= arr[k+1] >= . . . >= arr[j]
    Examples: 

    Input: arr[] = [12, 4, 78, 90, 45, 23]
    Output: 5
*/

class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = (int)arr.size();
        if(n == 1) return 1;
        int ans = 0;
        int i = 1;
        int ind = 0;
        int last = -1;
        int mini = INT_MAX;
        while(i < n)
        {
            int j = i;
            while(j < n && arr[j-1] <= arr[j])
            {
                if(last != -1) ans = max(ans, j-last+1);
                else ans = max(ans, j-i+1);
                j++;
            }
            mini = INT_MAX;
            while(j < n && arr[j-1] >= arr[j])
            {
                if(mini > arr[j])
                {
                    mini = arr[j];
                    ind = j;
                }
                j++;
            }
            if(last != -1) ans = max(ans, j-last+1);
            else ans = max(ans, j-i+1);
            if(j == n && last != -1)
            {
                ans -= 1;
                break;
            }
            last = ind;
            i = j;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.bitonic(arr)<<endl;
}
/*
14
3 2 1 1 2 3 4 5 5 4 3 2 1 1
*/

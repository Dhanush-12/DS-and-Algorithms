#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given an array arr[]. Initially, you have another array containing only 0s.
    In one operation, you may either:

    Choose any one element and increase its value by 1, or
    Double the values of all elements in the array simultaneously.
    Find the minimum number of operations required to transform the initial all-zero array into the given array arr[].

    Examples:

    Input: arr[] = [16, 16, 16]
    Output: 7
*/
class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int ans = 0;
        int maxi = 0;
        for(int x : arr)
        {
            ans += __builtin_popcount(x);
            maxi = max(maxi, x);
        }
        while(maxi > 1)
        {
            ans++;
            maxi >>= 1;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.countMinOperations(arr)<<endl;

}

#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given an array arr[], choose any subset of elements (possibly all elements) such
    that the XOR of the chosen elements is maximized.

    Examples:

    Input : arr[] = [2, 4, 5]
    Output: 7
    Explanation: The subset {2, 5} has the maximum XOR value.
    Input : arr[] = [9, 8, 5]
    Output: 13
    Explanation: The subset {8, 5} has the maximum XOR value.
*/
class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = (int)arr.size();
        vector<int> basis(31, 0);

        for(int x : arr)
        {
            for(int mask=30;mask>=0 && x != 0;mask--)
            {
                if(!((1 << mask)&x)) continue;

                if(basis[mask] == 0)
                {
                    basis[mask] = x;
                    break;
                }
                x ^= basis[mask];
            }
        }
        int ans = 0;
        for(int i=30;i>=0;i--)
        {
            ans = max(ans, ans^basis[i]);
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
    cout<<s.maxSubsetXOR(arr)<<endl;
}
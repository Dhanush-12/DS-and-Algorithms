#include<bits/stdc++.h>
using namespace std;
/*
Porblem: You are given an integer array nums and an integer k. The frequency of an element x is the number of times it occurs in an
array. An array is called good if the frequency of each element in this array is less than or equal to k. Return the length of the
longest good subarray of nums. A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray.
Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.

Example 2:

Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int left = 0;
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            while(left < i && mp[nums[i]] > k)
            {
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.maxSubarrayLength(arr, k)<<endl;
}
/*
8 2
1 2 3 1 2 3 1 2

8 1
1 2 1 2 1 2 1 2

7 4
5 5 5 5 5 5 5
*/

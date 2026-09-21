#include<bits/stdc++.h>
using namespace std;
/*
    Problem : Given an array arr[] containing both positive and negative integers, the task is
    to find the length of the longest subarray with a sum equals to 0.

    Note: A subarray is a contiguous part of an array, formed by selecting one or more
    consecutive elements while maintaining their original order.

    Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
    Output: 5

    Input: arr[] = [2, 10, 4]
    Output: 0

    Input: arr[] = [1, 0, -4, 3, 1, 0]
    Output: 5
*/
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = (int)arr.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int ans = 0, sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];

            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
                continue;
            }

            ans = max(ans, i-mp[sum]);
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
    cout<<s.maxLength(arr)<<endl;
}
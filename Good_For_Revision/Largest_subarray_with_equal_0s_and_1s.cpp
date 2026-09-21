#include<bits/stdc++.h>
using namespace std;
/*
    Problem :Given an array arr of 0s and 1s. Find and return the length of the longest subarray
    with equal number of 0s and 1s.
*/
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = (int)arr.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0, ans = 0;
        for(int i=0;i<n;i++)
        {
            sum += (arr[i] == 0) ? -1 : 1;
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
    cout<<s.maxLen(arr)<<endl;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Time Complexity: O(n*log(n) + n)
    // Space Complexity: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int sum = arr[i].first+arr[j].first;
            if(sum == target)
            {
                return {arr[i].second,arr[j].second};
            }
            else if(sum > target) j--;
            else i++;
        }
        return {-1,-1};
    }
    // Overriding the above original function
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> twoSum(int n, vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                return {i, mp[target-nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
int main()
{
    int n, t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    vector<int>ans = s.twoSum(n, arr, t);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}

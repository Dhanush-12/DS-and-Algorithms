#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        long long ans = INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int low = j+1, high = n-1;
                int mid;
                while(low <= high)
                {
                    mid = low + (high-low)/2;
                    long long sum = nums[i]+nums[j]+nums[mid];
                    if(sum == target) return sum;
                    if(llabs(sum - target) < llabs(ans - target))
                        ans = sum;
                    if(sum > target) high = mid-1;
                    else low = mid+1;
                }
            }
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
    int t;
    cin>>t;
    Solution s;
    cout<<s.threeSumClosest(arr, t)<<endl;
}

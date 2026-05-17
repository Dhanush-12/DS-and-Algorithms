#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums)
{
    int n=(int)nums.size();
    sort(nums.begin(),nums.end());
    vector<int>dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]%nums[j]==0)
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    vector<int>ans;
    int maxi=*max_element(dp.begin(),dp.end());
    int last=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(maxi==dp[i])
        {
            if(last==-1 || last%nums[i]==0)
            {
                last=nums[i];
                ans.push_back(nums[i]);
                maxi--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=largestDivisibleSubset(arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
/*
8
10 9 2 5 30 70 101 188
*/

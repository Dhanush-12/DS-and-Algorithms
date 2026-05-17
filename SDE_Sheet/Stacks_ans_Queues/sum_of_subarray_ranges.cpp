#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int sum_of_subarray_ranges(int n,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
            ans+=(maxi-mini);
        }
    }
    return ans;
}
void pref_smallest_or_equal(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[0],0});
    ans.push_back(-1);
    for(int i=1;i<n;i++)
    {
        if(s.top().first<=arr[i])
        {
            ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
        else
        {
            while(!s.empty() && s.top().first>arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
}
void suffsmallest(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[n-1],n-1});
    ans.push_back(n);
    for(int i=n-2;i>=0;i--)
    {
        if(s.top().first<arr[i])
        {
            ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
        else
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(n);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
    reverse(ans.begin(),ans.end());
}
int sum_of_subarray_mins(int n,vector<int>&arr)
{
    int ans=0;
    vector<int>pse,nse;
    suffsmallest(n,arr,nse);
    pref_smallest_or_equal(n,arr,pse);
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        ans=(ans+(right*left*arr[i])%mod)%mod;
    }
    return ans;
}
void pref_largest_or_equal(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[0],0});
    ans.push_back(-1);
    for(int i=1;i<n;i++)
    {
        if(s.top().first>=arr[i])
        {
            ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
        else
        {
            while(!s.empty() && s.top().first<arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
}
void sufflargest(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[n-1],n-1});
    ans.push_back(n);
    for(int i=n-2;i>=0;i--)
    {
        if(s.top().first>arr[i])
        {
            ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
        else
        {
            while(!s.empty() && s.top().first<=arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(n);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
    reverse(ans.begin(),ans.end());
}
int sum_of_subarray_maxs(int n,vector<int>&arr)
{
    int ans=0;
    vector<int>ple,nle;
    sufflargest(n,arr,nle);
    pref_largest_or_equal(n,arr,ple);
    for(int i=0;i<n;i++)
    {
        int left=i-ple[i];
        int right=nle[i]-i;
        ans=(ans+(right*left*arr[i])%mod)%mod;
    }
    return ans;
}
// Basically the problem states to give the sum of differences of (largest and smallest) of all the subarrays of the given array.
// That is -> sum of (Li-Si)+(Li+1 - Si+1)+()....;
// That deduces to -> (Sum of all the largest ele of subarrays) - (Sum of all the smallest ele of subarrays);
// That is -> (sum_of_subarrays_maxs)-(sum_of_subarrays_mins);
// Time complexity : O(10*n) ~ O(n);
int optimal_sum_of_subarray_ranges(int n,vector<int>&arr)
{
    int largesum=sum_of_subarray_maxs(n,arr);
    int smallsum=sum_of_subarray_mins(n,arr);
    return largesum-smallsum;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=optimal_sum_of_subarray_ranges(n,arr);
    cout<<ans<<endl;
}
/*
4
1 4 3 2

 ans: 13
*/

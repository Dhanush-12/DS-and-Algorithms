#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(n * ~log(n));
vector<int>brute(int n,vector<int>&arr)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    for(auto it:mp)
    {
        if(it.second==1) ans.push_back(it.first);
    }
    return ans;
}
// Time complexity : O(n);
vector<int>optimal(int n,vector<int>&arr)
{
    int xx=0;
    for(int i=0;i<n;i++)
    {
        xx^=arr[i];
    }
    int right_most_set_bit=(xx&(xx-1))^xx;
    int bucket1=0,bucket2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]&right_most_set_bit)
        {
            bucket1=bucket1^arr[i];
        }
        else
        {
            bucket2^=arr[i];
        }
    }
    return {bucket1,bucket2};
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=optimal(n,arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}

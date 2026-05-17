#include<bits/stdc++.h>
using namespace std;
// Time complexity : O((n-k)*k);
vector<int> sliding_window_maximum_bruteforce(int n,int k,vector<int>&arr)
{
    vector<int>ans;
    for(int i=0;i<=n-k;i++)
    {
        int maxi=arr[i];
        for(int j=i;j<(i+k);j++)
        {
            maxi=max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}
// Time complexity : O(2*n);
vector<int> sliding_window_maximum_optimal(int n,int k,vector<int>&arr)
{
    vector<int>ans;
    deque<int>q;
    for(int i=0;i<n;i++)
    {
        if(!q.empty() && q.front()<=(i-k))
        {
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()]<=arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if(i>=(k-1))
        {
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=sliding_window_maximum_optimal(n,k,arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
/*
9 3
1 3 -1 -3 5 3 2 1 6
*/

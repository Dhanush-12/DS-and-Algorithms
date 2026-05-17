#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(n^2);
int online_stock_span_bruteforce(int n,vector<int>&arr)
{
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        int j=i-1;
        while(j>=0 && arr[j]<=arr[i])
        {
            cnt++;
            j--;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
// Time complexity : O(2*n)
int online_stock_span_optimal(int n,vector<int>&arr)
{
    int ans=0;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && s.top().first<=arr[i])
        {
            s.pop();
        }
        ans=i-(s.empty()?-1:s.top().second);
        s.push({arr[i],i});
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<online_stock_span_optimal(n,arr)<<endl;
}
/*
7
7 2 1 3 3 1 8
*/

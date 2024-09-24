#include<bits/stdc++.h>
using namespace std;
int largest_rectangle_hist_optimal(int n,vector<int>&arr)
{
    int ans=0;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            int ele=s.top();
            s.pop();
            int nse=i;
            int pse=(s.empty())?(-1):(s.top());
            ans=max(ans,(nse-pse-1)*arr[ele]);
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int ele=s.top();
        s.pop();
        int nse=n;
        int pse=(s.empty())?(-1):(s.top());
        ans=max(ans,arr[ele]*(nse-pse-1));
    }
    return ans;
}
// Prerequiste / Referencing problem is largest rectangle in the histogram
// Time complexity : O(m*n)+O(n * 2*m);
int maximal_rectangle_in_grid(int n,int m,vector<vector<int>>&arr)
{
    vector<vector<int>>prefsum(n,vector<int>(m,0));
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j][i]==0) sum=0;
            sum+=arr[j][i];
            prefsum[j][i]=sum;
        }
    }
    for(int i=0;i<n;i++)
    {
        ans=max(ans,largest_rectangle_hist_optimal(m,prefsum[i]));
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans=maximal_rectangle_in_grid(n,m,arr);
    cout<<ans<<endl;
}
/*
4 5
1 0 1 0 1
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
*/

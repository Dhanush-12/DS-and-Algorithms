#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
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
// Time complexity : O(n*(n+m))
// Space Complexity : O(n)
int maximalAreaOfSubmatrixOfAll(vector<vector<int>>&arr,int n,int m)
{
    int ans=0;
    vector<int>heights(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1) heights[j]++;
            else heights[j]=0;
        }
        int area=largest_rectangle_hist_optimal((int)heights.size(),heights);
        ans=max(ans,area);
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<maximalAreaOfSubmatrixOfAll(arr,n,m)<<endl;
}
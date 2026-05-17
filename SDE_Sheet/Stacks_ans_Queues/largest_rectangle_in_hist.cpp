#include<bits/stdc++.h>
using namespace std;
void pref_smallest(int n,vector<int>&arr,vector<int>&ans)
{
    stack<pair<int,int>>s;
    s.push({arr[0],0});
    ans.push_back(-1);
    for(int i=1;i<n;i++)
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
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top().second);
            s.push({arr[i],i});
        }
    }
}
void suff_smallest(int n,vector<int>&arr,vector<int>&ans)
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
// Time complexity : O(4*n)
int largest_rectangle_hist(int n,vector<int>&arr)
{
    vector<int>pse,nse;
    pref_smallest(n,arr,pse);
    suff_smallest(n,arr,nse);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,(arr[i]*(nse[i]-pse[i]-1)));
    }
    return ans;
}
// Time complexity : O(n)
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
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=largest_rectangle_hist_optimal(n,arr);
    cout<<ans<<endl;
}
/*
6
2 1 5 6 2 3

8
3 2 10 11 5 10 6 3
*/

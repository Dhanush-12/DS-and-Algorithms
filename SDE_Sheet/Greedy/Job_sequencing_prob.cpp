#include<bits/stdc++.h>
using namespace std;
// Time complexity O(nlog(n));
int solve(int n,vector<int>&deadline,vector<int>&profit)
{
    int ans=0;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({deadline[i],profit[i]});
    }
    sort(arr.begin(),arr.end(),[&](pair<int,int>a,pair<int,int>b){
          return a.second>b.second;
    });
    int maxdead=*max_element(deadline.begin(),deadline.end());
    unordered_map<int,int>mp;
    for(int i=1;i<=maxdead;i++) mp[i]=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=maxdead;j>=0;j--)
        {
            if(mp[j]==-1)
            {
                 mp[j]=1;
                 ans+=profit[i];
                 break;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>deadline(n),profit(n);
    for(int i=0;i<n;i++) cin>>deadline[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    cout<<solve(n,deadline,profit)<<endl;
}

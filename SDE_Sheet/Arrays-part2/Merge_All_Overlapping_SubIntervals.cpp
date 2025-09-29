#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> optimal(int n,vector<pair<int,int>>&arr)
{
    vector<pair<int,int>>ans;
    sort(arr.begin(),arr.end());
    int low=arr[0].first;
    int high=arr[0].second;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first <= high)
        {
            high=max(high,arr[i].second);
        }
        else
        {
            ans.push_back({low,high});
            low=arr[i].first;
            high=arr[i].second;
        }
    }
    ans.push_back({low,high});
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    vector<pair<int,int>>ans=optimal(n,arr);
    cout<<"Answer using better solution: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
/*
8
1 3
2 6
8 9
9 11
8 10
2 4
15 18
16 17
*/

#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(nlog(n) + ~O(n^2));
vector<vector<int>>brute(int n,vector<vector<int>>&arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        int start=arr[i][0];
        int endd=arr[i][1];
        if(!ans.empty() && arr[i][1]<=ans.back()[1]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j][0]<=arr[i][1])
            {
                endd=max(endd,arr[j][1]);
            }
            else break;
        }
        ans.push_back({start,endd});
    }
    return ans;
}
// Time complexity : O(nlog(n) + n);
vector<vector<int>>optimal(int n,vector<vector<int>>&arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || arr[i][0]>ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<vector<int>>ans=optimal(n,arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
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

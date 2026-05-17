#include<bits/stdc++.h>
using namespace std;
vector<int>spiralorder(vector<vector<int>>&arr,int n,int m)
{
    vector<int>ans;
    int tot=n*m;
    int cnt=0;
    int sr=0,er=n-1,sc=0,ec=m-1;
    while(sr<=er && sc<=ec)
    {
        for(int i=sc;i<=ec;i++)
        {
            ans.push_back(arr[sr][i]);
            cnt++;
        }
        sr++;
        if(cnt==tot) break;
        for(int i=sr;i<=er;i++)
        {
            ans.push_back(arr[i][ec]);
            cnt++;
        }
        ec--;
        if(cnt==tot) break;
        for(int i=ec;i>=sc;i--)
        {
            ans.push_back(arr[er][i]);
            cnt++;
        }
        er--;
        if(cnt==tot) break;
        for(int i=er;i>=sr;i--)
        {
            ans.push_back(arr[i][sc]);
            cnt++;
        }
        sc++;
        if(cnt==tot) break;
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
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    vector<int>ans=spiralorder(arr,n,m);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

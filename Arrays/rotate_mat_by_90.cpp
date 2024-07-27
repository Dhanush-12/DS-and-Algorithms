#include<bits/stdc++.h>
using namespace std;
void rotate90(vector<vector<int>>&arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        reverse(arr[i].begin(),arr[i].end());
    }
}
void rotate90(int n,int m,vector<vector<int>>&arr)
{
    vector<vector<int>>ans;
    for(int j=0;j<m;j++)
    {
        vector<int>temp;
        for(int i=n-1;i>=0;i--)
        {
            temp.push_back(arr[i][j]);
        }
        ans.push_back(temp);
    }
    arr=ans;
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
    rotate90(arr,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

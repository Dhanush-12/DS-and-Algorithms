#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Rotate matrix to 90 degrees
void RotateMatrix(int n, int m, vector<vector<int>>&arr)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        reverse(arr[i].begin(),arr[i].end());
    }
    return;
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
    RotateMatrix(n,m,arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
/*
6
7 1 5 3 6 4
*/

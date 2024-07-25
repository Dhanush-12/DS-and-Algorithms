#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <bits/stdc++.h>
// Time complexity : O(n*m*(n+m) + n*m)
void set_matrix_to_zero(vector<vector<int>>&arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                int row=i,col=j;
                for(int k=0;k<n;k++)
                {
                    if(arr[k][j])
                    {
                        arr[k][j]=-1;
                    }
                }
                for(int k=0;k<m;k++)
                {
                    if(arr[i][k])
                    {
                        arr[i][k]=-1;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1) arr[i][j]=0;
        }
    }
}
// Time complexity : O(2*n*m)
void set_matrix_to_zero(int n,int m,vector<vector<int>>&arr)
{
    vector<int>row(n,0),col(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i] || col[j]) arr[i][j]=0;
        }
    }
}
// Time Complexity : O(n*m)
void set_matrix_to_zero(int n,vector<vector<int>>&arr,int m)
{
    int col1=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<m;j++)
        {
            if(arr[i][j]==0)
            {
                if(i==0) col1=0;
                else
                {
                    arr[0][j]=0;
                    arr[i][0]=0;
                }
            }
        }
    }
    if(col1==0)
    {
        for(int i=0;i<m;i++) arr[0][i]=0;
    }
    if(arr[0][0]==0) for(int i=0;i<n;i++) arr[i][0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[0][j]==0 && arr[i][0]==0) arr[i][j]=0;
        }
    }
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
    set_matrix_to_zero(n,m,arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

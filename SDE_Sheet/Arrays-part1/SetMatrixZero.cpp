#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Time complexity : O((n*m)*(n_m));
// Space Complexity : O(1)
void bruteforce_setZeros(int n,int m,vector<vector<int>>&arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                for(int k=0;k<n;k++)
                {
                    if(arr[k][j]!=0) arr[k][j]=-1;
                }
                for(int k=0;k<m;k++)
                {
                    if(arr[i][k]!=0) arr[i][k]=-1;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1)
            {
                arr[i][j]=0;
            }
        }
    }
}
// Time Complexity : O(n*m)
// Space Complexity : O(n+m);
void better_setZeros(int n,int m,vector<vector<int>>&arr)
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
            if(row[i] || col[j])
            {
                arr[i][j]=0;
            }
        }
    }
}
// Time Complexity : O(n*m)
// Space Complexity : O(1);
void optimal_setZeros(int n,int m,vector<vector<int>>&arr)
{
    int col=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                if(i==0)
                {
                    col=1;
                }
                else if(j==0)
                {
                    arr[0][0]=0;
                }
                else
                {
                    arr[0][j]=0;
                    arr[i][0]=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[0][j]==0 || arr[i][0]==0)
            {
                arr[i][j]=0;
            }
        }
    }
    if(arr[0][0]==0)
    {
        for(int i=0;i<n;i++)
        {
            arr[i][0]=0;
        }
    }
    if(col==1)
    {
        for(int i=0;i<m;i++)
        {
            arr[0][i]=0;
        }
    }
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
    optimal_setZeros(n,m,arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*

*/

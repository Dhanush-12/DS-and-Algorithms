#include<bits/stdc++.h>
using namespace std;
const int inf=1e8;
void floydWarshall(int n,vector<vector<int>> &arr) {
    for(int i=0;i<n;i++) arr[i][i]=0;
    for(int vis=0;vis<n;vis++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][vis]<inf && arr[vis][j]<inf)
                {
                    int newd=arr[i][vis]+arr[vis][j];
                    if(newd<arr[i][j]) arr[i][j]=newd;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    floydWarshall(n,arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

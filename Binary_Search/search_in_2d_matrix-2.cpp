#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define sp(x, y) fixed << setprecision(x) << y
#define mod (int)(1e9 + 7)
#define nl endl
using namespace std;
// Time Complexity : O(n+m)
pair<int,pair<int,int>> optimal2(int n,int m,vector<vector<int>>&arr,int k)
{
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (arr[row][col] == k) return {1,{row,col}};
        else if (arr[row][col] < k) row++;
        else col--;
    }
    return {0,{-1,-1}};
}
// Time complexity : O(n * m);
bool searchinmatrix2(int n,int m,vector<vector<int>>&arr,int k)
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(arr[i][j]==k) return 1;
       }
   }
   return 0;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    pair<int,pair<int,int>>p=optimal2(n,m,arr,k);
    int f=p.first;
    if(f)
    {
        cout<<"Found"<<endl;
        cout<<p.second.first<<" "<<p.second.second<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}

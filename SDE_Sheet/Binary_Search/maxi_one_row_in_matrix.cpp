#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define sp(x, y) fixed << setprecision(x) << y
#define mod (int)(1e9 + 7)
#define nl endl
using namespace std;
// Time Complexity : O(n*m)
int optimal(int n,int m,vector<vector<int>>&arr)
{
    int ind=-1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int low=0,high=m-1;
        int index=-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(arr[i][mid]==1)
            {
                index=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(index!=-1)
        {
            int cnt=m-index;
            if(maxi<cnt)
            {
                maxi=cnt;
                ind=i;
            }
            else if(maxi==cnt)
            {
                ind=min(ind,i);
            }
        }
    }
    return ind;
}
// Time complexity : O(n * log(m));
int maxirowones(int n,int m,vector<vector<int>>&arr)
{
    int ind=-1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
       int cnt=0;
       for(int j=0;j<m;j++)
       {
           if(arr[i][j]==1) cnt++;
       }
       if(cnt)
       {
           if(maxi<cnt)
           {
               maxi=cnt;
               ind=i;
           }
           else if(maxi==cnt)
           {
               ind=min(ind,i);
           }
       }
    }
    return ind;
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
    cout<<optimal(n,m,arr)<<endl;
}

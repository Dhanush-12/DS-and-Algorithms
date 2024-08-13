#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define sp(x, y) fixed << setprecision(x) << y
#define mod (int)(1e9 + 7)
#define nl endl
using namespace std;
// Time Complexity : O(log(n)*log(m))
int optimal(int n,int m,vector<vector<int>>&arr,int k)
{
   int lown=0,highn=n-1;
   while(lown<=highn)
   {
       int midn=(lown+highn)>>1;
       if(arr[midn][0]<=k && arr[midn][m-1]>=k)
       {
           int lowm=0,highm=m-1;
           while(lowm<=highm)
           {
               int midm=(lowm+highm)>>1;
               if(arr[midn][midm]==k) return 1;
               else if(arr[midn][midm]>k)
               {
                   highm=midm-1;
               }
               else
               {
                   lowm=midm+1;
               }
           }
           return 0;
       }
       else if(k>arr[midn][m-1])
       {
           lown=midn+1;
       }
       else
       {
           highn=midn-1;
       }
   }
   return 0;
}
// Time complexity : O(n * m);
bool searchinmatrix(int n,int m,vector<vector<int>>&arr,int k)
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
    if(optimal(n,m,arr,k))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}

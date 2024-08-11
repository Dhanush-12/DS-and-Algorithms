#include<bits/stdc++.h>
using namespace std;
// Time complexity : N*K;
double brute(int n,vector<int> &arr, int k)
{
    vector<int>fr(n-1,0);
    for(int i=1;i<=k;i++)
    {
        double maxseg=-1;
        int maxind=-1;
        for(int i=0;i<n-1;i++)
        {
            double diff=(arr[i+1]-arr[i]);
            double seclen=diff/(double)(fr[i]+1);
            if(seclen>maxind)
            {
                maxind=seclen;
                maxind=i;
            }
        }
        fr[maxind]=i;
    }
    double ans=-1;
    for(int i=0;i<n-1;i++)
    {
        double diff=(arr[i+1]-arr[i]);
        double seclen=diff/(double)(fr[i]+1);
        ans=max(ans,seclen);
    }
    return ans;
}
// Time complexity : KlogN + NlogN;
double optimal(int n,vector<int> &arr, int k)
{
    vector<int>fr(n-1,0);
    priority_queue<pair<double,int>>q;
    for(int i=0;i<n-1;i++)
    {
        q.push({arr[i+1]-arr[i],i});
    }
    for(int i=1;i<=k;i++)
    {
        auto it=q.top();
        q.pop();
        int ind=it.second;
        fr[ind]++;
        double diff=arr[ind+1]-arr[ind];
        double newdiff=diff/(double)(fr[ind]+1);
        q.push({newdiff,ind});
    }
    return q.top().first;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    double ans=brute(n,arr,k);
    cout<<ans<<endl;
}
/*
6 4
0 3 4 7 9 10
*/

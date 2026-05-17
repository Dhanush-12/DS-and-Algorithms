#include<bits/stdc++.h>
using namespace std;
//Time complexity : O(nlog(n) + mlog(m) + m)
int solve(int n,int m,vector<int>greed,vector<int>coockies)
{
    sort(greed.begin(),greed.end());
    sort(coockies.begin(),coockies.end());
    int cnt=0;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(coockies[j]>=greed[i])
        {
            cnt++;
            i++,j++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>greed(n),coockies(m);
    for(int i=0;i<n;i++) cin>>greed[i];
    for(int i=0;i<m;i++) cin>>coockies[i];
    cout<<solve(n,m,greed,coockies)<<endl;
}

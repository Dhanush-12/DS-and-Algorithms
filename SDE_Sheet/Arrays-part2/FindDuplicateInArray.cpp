#include<bits/stdc++.h>
using namespace std;
//Given array of N+1 size where all the elements are from 1 to N, assuming there is only one duplicate, the task is to find the duplicate number.
int duplicateInArray(int n,vector<int>&arr)
{
    vector<int>vis(n,0);
    for(int i:arr)
    {
        if(vis[i]) return i;
        vis[i]=1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=0;i<n+1;i++) cin>>arr[i];
    cout<<duplicateInArray(n+1,arr)<<endl;
}
/*
4
1 3 4 2 2
*/

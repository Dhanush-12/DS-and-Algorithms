#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <bits/stdc++.h>
int longest_consecutive_sequence(vector<int>&arr,int n)
{
    int ans=1;
    unordered_set<int>s;
    for(int i=0;i<n;i++) s.insert(arr[i]);
    for(int i=0;i<n;i++)
    {
        if(s.count(arr[i]-1)) continue;
        else
        {
            int cnt=1;
            int st=arr[i]+1;
            while(s.count(st))
            {
                cnt++;
                st++;
            }
            ans=max(ans,cnt);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=longest_consecutive_sequence(arr,n);
    cout<<ans<<endl;
}

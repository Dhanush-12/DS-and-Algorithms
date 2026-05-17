#include<bits/stdc++.h>
using namespace std;
// Here in this problem, the array is considered as circular.
// Time complexity : O(4n)
vector<int>next_greater2(int n,vector<int>&arr)
{
    vector<int>ans;
    stack<int>s;
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<=s.top())
        {
            s.push(arr[i]);
        }
        else
        {
            while(!s.empty() && arr[i]>s.top()) s.pop();
            s.push(arr[i]);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]<s.top())
        {
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else
        {
            while(!s.empty() && arr[i]>=s.top()) s.pop();
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top());
            s.push(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=next_greater2(n,arr);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
12
4 12 5 3 1 2 5 3 1 2 4 6
*/

#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(2N);
vector<int>next_greater(int n,vector<int>&arr)
{
    vector<int>ans;
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            ans.push_back(-1);
            s.push(arr[i]);
            continue;
        }
        if(arr[i]<s.top())
        {
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else
        {
            while(!s.empty() && arr[i]>=s.top())
                s.pop();
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
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
    vector<int>ans=next_greater(n,arr);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
12
4 12 5 3 1 2 5 3 1 2 4 6
*/

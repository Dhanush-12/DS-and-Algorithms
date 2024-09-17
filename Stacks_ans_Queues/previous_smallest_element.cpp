#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(n);
vector<int>prev_smallest(int n,vector<int>&arr)
{
    vector<int>ans;
    stack<int>s;
    s.push(arr[0]);
    ans.push_back(-1);
    for(int i=1;i<n;i++)
    {
        if(s.top()<arr[i])
        {
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else
        {
            while(!s.empty() && s.top()>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top());
            s.push(arr[i]);
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
    vector<int>ans=prev_smallest(n,arr);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
12
4 12 5 3 1 2 5 3 1 2 4 6
*/

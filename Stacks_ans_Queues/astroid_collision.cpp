#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(2n) ~ O(n);
vector<int>astroid_collision(int n,vector<int>&arr)
{
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                s.push(arr[i]);
            }
            else
            {
                if(s.empty() || s.top()<0)
                {
                    s.push(arr[i]);
                }
                else
                {
                    while(!s.empty() && s.top()<abs(arr[i]) && s.top()>0)
                    {
                        s.pop();
                    }
                    if(s.empty())
                    {
                        s.push(arr[i]);
                        continue;
                    }
                    else if(s.top()>abs(arr[i]))
                    {
                        continue;
                    }
                    else if(s.top()==abs(arr[i]))
                    {
                        s.pop();
                        continue;
                    }
                    s.push(arr[i]);
                }
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
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
    vector<int>ans=astroid_collision(n,arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
/*
10
4 7 1 1 2  -3 -7 17 15 -16
 ans: [4 17]
*/

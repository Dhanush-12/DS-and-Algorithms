#include<bits/stdc++.h>
using namespace std;
class Solution {
    void previousSmallerElement(vector<int>&arr, vector<int>&ans)
    {
        int n=(int)arr.size();
        stack<int>s;
        s.push(0);
        ans.push_back(-1);
        for(int i=1;i<n;i++)
        {
            if(arr[i] > arr[s.top()])
            {
                ans.push_back(s.top());
                s.push(i);
            }
            else
            {
                while(!s.empty() && arr[i]<=arr[s.top()])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(s.top());
                }
                s.push(i);
            }
        }
        return;
    }
    void nextSmallerElement(vector<int>&arr, vector<int>&ans)
    {
        int n=(int)arr.size();
        stack<int>s;
        s.push(n-1);
        ans.push_back(n);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] > arr[s.top()])
            {
                ans.push_back(s.top());
                s.push(i);
            }
            else
            {
                while(!s.empty() && arr[i]<=arr[s.top()])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans.push_back(n);
                }
                else
                {
                    ans.push_back(s.top());
                }
                s.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=(int)arr.size();
        vector<int>prevSmall,nextSmall;
        previousSmallerElement(arr, prevSmall);
        nextSmallerElement(arr, nextSmall);
        vector<int>ans(n);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int dis = nextSmall[i]-prevSmall[i]-1;
            mp[dis].push_back(arr[i]);
        }
        int maxi=mp[n][0];
        ans[n-1]=maxi;
        for(int i=n-1;i>=1;i--)
        {
            if(mp.find(i) != mp.end())
            {
                for(auto itt:mp[i])
                {
                    maxi=max(maxi, itt);
                }
                ans[i-1]=maxi;
            }
            else
            {
                ans[i-1]=maxi;
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    Solution s;
    vector<int>ans=s.maxOfMins(arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(n^3);
vector<vector<int>>bruteforce(int n,vector<int>&arr,int sum)
{
    set<vector<int>>s;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==sum)
                {
                    if(!s.count({arr[i],arr[j],arr[k]}))
                    {
                        ans.push_back({i,j,k});
                        s.insert({arr[i],arr[j],arr[k]});
                    }
                }
            }
        }
    }
    return ans;
}
// Time complexity : ~ O(n^2 log(n));
vector<vector<int>>better(int n,vector<int>&arr,int sum)
{
    set<vector<int>>ss;
    for(int i=0;i<n;i++)
    {
        set<int>s;
        for(int j=i+1;j<n;j++)
        {
            int th=sum-(arr[i]+arr[j]);
            if(s.count(th))
            {
                vector<int>temp={arr[i],arr[j],th};
                sort(temp.begin(),temp.end());
                ss.insert(temp);
            }
            s.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(ss.begin(),ss.end());
    return ans;
}
// Time complexity : O(nlog(n) + ~n^2);
vector<vector<int>>optimal(int n,vector<int>arr,int sum)
{
   sort(arr.begin(),arr.end());
   vector<vector<int>>ans;
   for(int i=0;i<n;i++)
   {
       if(i>0 && arr[i]==arr[i-1]) continue;
       int j=i+1,k=n-1;
       while(j<k)
       {
           int s=arr[i]+arr[j]+arr[k];
           if(s<sum)
           {
               j++;
           }
           else if(s>sum)
           {
               k--;
           }
           else
           {
               vector<int>temp={arr[i],arr[j],arr[k]};
               ans.push_back(temp);
               j++,k--;
               while(j<k && arr[j]==arr[j-1]) j++;
               while(j<k && arr[k]==arr[k+1]) k--;
           }
       }
   }
   return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>>ans=optimal(n,arr,k);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

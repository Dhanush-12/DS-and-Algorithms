#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(n^4)
vector<vector<int>>brute(int n,vector<int>&arr,int sum)
{
    vector<vector<int>>ans;
    set<vector<int>>s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    if((arr[i]+arr[j]+arr[k]+arr[l])==sum)
                    {
                        //cout<<arr[i]+arr[j]+arr[k]+arr[l]<<endl;
                        vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        if(!s.count(temp))
                        {
                            ans.push_back(temp);
                            s.insert(temp);
                        }
                    }
                }
            }
        }
    }
    return ans;
}
// Time complexity : O(n^3 * ~log(n))
vector<vector<int>>better(int n,vector<int>&arr,int sum)
{
   set<vector<int>>s;
   vector<vector<int>>ans;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           unordered_set<int>ss;
           for(int k=j+1;k<n;k++)
           {
               int req=sum-(arr[i]+arr[j]+arr[k]);
               if(ss.count(req))
               {
                   vector<int>temp={arr[i],arr[j],arr[k],req};
                   sort(temp.begin(),temp.end());
                   if(!s.count(temp))
                   {
                       ans.push_back(temp);
                       s.insert(temp);
                   }
               }
               ss.insert(arr[k]);
           }
       }
   }
   return ans;
}
// Time complexity : O(n*log(n) + n^3)
vector<vector<int>>optimal(int n,vector<int>&arr,int sum)
{
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
                int s=arr[i]+arr[j]+arr[k]+arr[l];
                if(sum==s)
                {
                    vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++,l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(l>k && arr[l]==arr[l+1]) l--;
                }
                else if(s<sum) k++;
                else l--;
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
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>>ans=better(n,arr,k);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

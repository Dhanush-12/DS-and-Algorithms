#include<bits/stdc++.h>
using namespace std;
int majority_element_nby3(int n,vector<int>&arr)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]>(n/3))
            return arr[i];
    }
    return -1;
}
int majority_element_nby3(vector<int>&arr,int n)
{
    int cnt=0;
    int ele;
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            cnt++;
            ele=arr[i];
        }
        if(arr[i]==ele) cnt++;
        else cnt--;
    }
    int fr=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele) fr++;
    }
    if(fr>(n/3)) return ele;
    return -1;
}
vector<int> majority_element_nby3_optimal(int n,vector<int>&arr)
{
    int cnt1=0,cnt2=0;
    int ele1=INT_MIN,ele2=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && ele2!=arr[i])
        {
            cnt1=1;
            ele1=arr[i];
        }
        else if(cnt2==0 && ele1!=arr[i])
        {
            cnt2=1;
            ele2=arr[i];
        }
        else if(arr[i]==ele1) cnt1++;
        else if(arr[i]==ele2) cnt2++;
        else
        {
            cnt1--,cnt2--;
        }
    }
    vector<int>ans;
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(ele1==arr[i])
            cnt1++;
        if(ele2==arr[i])
            cnt2++;
    }
    if(cnt1>=(n/3)) ans.push_back(ele1);
    if(cnt2>=(n/3)) ans.push_back(ele2);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=majority_element_nby3(arr,n);
    vector<int>ans1=majority_element_nby3_optimal(n,arr);
    //cout<<ans<<endl;
    for(int i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";
    cout<<endl;
}

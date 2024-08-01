#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(n+m);
// Space Complexity : O(n+m);
vector<int>brute(int n,int m,vector<int>&a,vector<int>&b)
{
    vector<int>ans;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<n)
    {
        ans.push_back(a[i]);
        i++;
    }
    while(j<m)
    {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
// Time Complexity : O(nlog(n) + mlog(m))+O(min(n,m));
// Space Complexity : O(1);
void optimal1(int n,int m,vector<int>&a,vector<int>&b)
{
    int l=n-1;
    int r=0;
    while(l>0 && r<m)
    {
        if(a[l]>b[r])
        {
            swap(a[l],b[r]);
            l--;
            r++;
        }
        else break;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}
// Time Complexity : O(log(n+m))*O(n+m);
void optimal2(int n,int m,vector<int>&a,vector<int>&b)
{
    int tot=(n+m);
    int gap=(tot+1)/(2);
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        while(right<tot)
        {
            if(left<n && right>=n)
            {
                if(a[left]>b[right-n])
                {
                    swap(a[left],b[right-n]);
                }
            }
            else if(left>=n)
            {
                if(b[left-n]>b[right-n])
                {
                    swap(b[left-n],b[right-n]);
                }
            }
            else
            {
                if(a[left]>a[right])
                {
                    swap(a[left],a[right]);
                }
            }
            left++,right++;
        }
        if(gap==1) break;
        gap=(gap+1)/2;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    vector<int>ans=brute(n,m,a,b);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    optimal2(n,m,a,b);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int j=0;j<m;j++) cout<<b[j]<<" ";
    cout<<endl;
}

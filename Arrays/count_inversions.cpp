#include<bits/stdc++.h>
using namespace std;
int cnt=0;
// Time complexity : O(n^2)
int brute(int n,vector<int>&arr)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j]) ans++;
        }
    }
    return ans;
}
void merger(int l, int m, int r,vector<int>&arr)
{
        int l1=m-l+1;
        int l2=r-m;
        int left[l1],right[l2];
        for(int i=0;i<l1;i++)
        {
            left[i]=arr[l+i];
        }
        for(int i=0;i<l2;i++)
        {
            right[i]=arr[m+1+i];
        }
        int ind1=0,ind2=0;
        int k=l;
        while(ind1<l1 && ind2<l2)
        {
            if(left[ind1]<=right[ind2])
            {
                arr[k]=left[ind1];
                k++;
                ind1++;
            }
            else
            {
                arr[k]=right[ind2];
                cnt+=(l1-ind1);
                k++;
                ind2++;
            }
        }
        while(ind1<l1)
        {
            arr[k]=left[ind1];
            k++;
            ind1++;
        }
        while(ind2<l2)
        {
            arr[k]=right[ind2];
            k++;
            ind2++;
        }
}
void optimal(int l,int r,vector<int>&arr)
{
    if(l>=r) return;
    int mid=(l+r)>>1;
    optimal(l,mid,arr);
    optimal(mid+1,r,arr);
    merger(l,mid,r,arr);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=brute(n,arr);
    cout<<"Using Brute force: ";
    cout<<ans<<endl;
    optimal(0,n-1,arr);
    cout<<"Using optimal : ";
    cout<<cnt<<endl;
}

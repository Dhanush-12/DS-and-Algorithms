#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define sp(x, y) fixed << setprecision(x) << y
#define mod (int)(1e9 + 7)
#define nl endl
using namespace std;
// Time complexity : O(log(min(n,m)))
int optimal(vector<int> &arr1, vector<int> &arr2)
{
    int n=(int)(arr1.size()),m=(int)(arr2.size());
    if(n>m) return optimal(arr2,arr1);
    int left=(n+m+1)/2;
    int low=0,high=n;
    int tot=n+m;
    while(low<=high)
    {
        int mid1=(low+high)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n) r1=arr1[mid1];
        if(mid2<m) r2=arr2[mid2];
        if(mid1-1>=0) l1=arr1[mid1-1];
        if(mid2-1>=0) l2=arr2[mid2-1];
        if(l1<=r2 && l2<=r1)
        {
            if(tot%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+ min(r1,r2)))/2.00;
        }
        else if(l1>r2)
        {
            high=mid1-1;
        }
        else low=mid1+1;
    }
    return 0;
}
// Time complexity : O(n+m)
int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
{
        int n=(int)(arr1.size()),m=(int)(arr2.size());
        vector<int>ans;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while(i<n) ans.push_back(arr1[i]),i++;
        while(j<m) ans.push_back(arr2[j]),j++;
        int tot=n+m;
        if(tot&1)
        {
            return ans[tot/2];
        }
        else
        {
            return ans[tot/2 - 1]+ans[tot/2];
        }
}
int main()
{
    fastread();
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),brr(m);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];
    cout<<optimal(arr,brr);
}

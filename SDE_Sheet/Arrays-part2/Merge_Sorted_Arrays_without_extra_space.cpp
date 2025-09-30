#include<bits/stdc++.h>
using namespace std;
// with using the extra space.
vector<int> betterApproach(int n,int m,vector<int>&a, vector<int>&b)
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
// without using the extra space.(optimal 1)
void optimalApproach1(int n,int m, vector<int>&a, vector<int>&b)
{
    int left=n-1;
    int right=0;
    while(left>=0 && right<m)
    {
        if(a[left]>b[right])
        {
            swap(a[left],b[right]);
            left--;
            right++;
        }
        else break;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return;
}
// without using extra space (optimal 2) using gap method also called as shell sort
void swapIfGreater(vector<int>&arr1, vector<int>&arr2, int ind1, int ind2)
{
    if(arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void optimalApproach2(int n,int m,vector<int>&a,vector<int>&b)
{
    int len=(n+m);
    int gap=(len/2)+(len%2);
    while(gap > 0)
    {
        int left=0,right=left+gap;
        while(right < len)
        {
            // arr1 and arr2
            if(left< n && right >=n)
            {
                swapIfGreater(a, b, left, right-n);
            }
            // arr2 and arr2
            else if(left>=n)
            {
                swapIfGreater(b, b, left-n, right-n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(a, a, left, right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<int>ans=betterApproach(n,m,a,b);
    cout<<"Answer using the better approach: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    vector<int>acopy=a;
    vector<int>bcopy=b;
    optimalApproach1(n,m,acopy,bcopy);
    cout<<"Answer using the optimal1 approach: "<<endl;
    for(int i=0;i<n;i++) cout<<acopy[i]<<' ';
    for(int i=0;i<m;i++) cout<<bcopy[i]<<' ';
    cout<<endl;
    optimalApproach2(n,m,a,b);
    cout<<"Answer using the optimal2 approach: "<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    for(int i=0;i<m;i++) cout<<b[i]<<' ';
    cout<<endl;
}
/*
4 5
1 3 5 7
0 2 6 8 9
*/

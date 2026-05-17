#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <bits/stdc++.h>
//Time complexity : O(n);
void next_permut(vector<int>&arr,int n)
{
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>arr[ind])
        {
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    next_permut(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

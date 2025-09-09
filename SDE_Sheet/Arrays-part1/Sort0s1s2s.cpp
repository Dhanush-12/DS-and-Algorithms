#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Sort0s1s2s using Dutch_National_Flag Algorithm
void Sort0s1s2s(int n, vector<int>&arr)
{
    int low=0,high=n-1,mid=0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"After sorting: ";
    Sort0s1s2s(n,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    cout<<endl;
}
/*
6
2 0 2 1 1 0
*/

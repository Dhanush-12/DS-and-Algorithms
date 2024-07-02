#include<bits/stdc++.h>
using namespace std;
void dnf_sort(vector<int>&arr)
{
    int n=(int)(arr.size());
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++,mid++;
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
    dnf_sort(arr);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;
// Time complextity : O(n^2) , besr case : O(n);
// Space Complexity : O(1);
void insertionsort(vector<int>&arr)
{
    int n=(int)(arr.size());
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionsort(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(n^2);
// Space Complexity : O(1);
void bubblesort(vector<int>&arr)
{
    int n=(int)(arr.size());
    for(int i=0;i<n;i++)
    {
        int f=0;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                //cout<<j<<" "<<j+1<<endl;
                swap(arr[j],arr[j+1]);
                f=1;
            }
        }
        if(f==0)
        {
            return;
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
    bubblesort(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

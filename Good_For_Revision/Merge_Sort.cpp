#include<bits/stdc++.h>
using namespace std;
// Given an array of integers, sort them in the ascending order using merge sort.
void merger(vector<int> &arr, int l, int mid, int r)
{
    int ln = mid-l+1;
    int rn = r-mid;

    vector<int> left(ln), right(rn);
    int k = l;
    for(int i=0;i<ln;i++)
    {
        left[i] = arr[k];
        k++;
    }
    k = mid+1;
    for(int i=0;i<rn;i++)
    {
        right[i] = arr[k];
        k++;
    }

    k = l;
    int ind1 = 0, ind2 = 0;
    while(ind1 < ln && ind2 < rn)
    {
        if(left[ind1] < right[ind2])
        {
            arr[k] = left[ind1];
            ind1++;
        }
        else
        {
            arr[k] = right[ind2];
            ind2++;
        }
        k++;
    }
    while(ind1 < ln)
    {
        arr[k] = left[ind1];
        ind1++;
        k++;
    }
    while(ind2 < rn)
    {
        arr[k] = right[ind2];
        ind2++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int l, int r)
{
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merger(arr, l, mid, r);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

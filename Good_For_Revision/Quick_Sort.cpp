#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Given an array arr[], with starting index low and ending index high, complete the
    functions partition() and quickSort() so that the array becomes sorted in ascending order.
*/
int partition(vector<int> &arr, int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    while(i < j)
    {
        while(i <= h && arr[i] <= pivot) i++;
        while(j >= l && arr[j] > pivot) j--; // arr[j] > pivot because we are taking pivot as arr[l]

        if(i > j) break;

        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int l, int h)
{
    if(l >= h) return;

    int partInd = partition(arr, l, h);
    quickSort(arr, l, partInd-1);
    quickSort(arr, partInd+1, h);
}
int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
/*
6
23 1 4 2 10 200
*/
#include<iostream>
using namespace std;
// right most element as the pivot element
int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
// another method by considering arr[low] as the pivot element;
// Time complexity : O(Nlog(N));
// Space complexity : O(1);
int partition1(int arr[],int l,int h)
{
    int p=arr[l];
    int i=l,j=h;
    while(i<j)
    {
        while(arr[i]<=p && i<=h-1)
        {
            i++;
        }
        while(arr[j]>p && j >= l+1)
        {
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}
void quicksort1(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition1(arr,low,high);
        quicksort1(arr,low,pi-1);
        quicksort1(arr,pi+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort1(arr,0,n-1);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
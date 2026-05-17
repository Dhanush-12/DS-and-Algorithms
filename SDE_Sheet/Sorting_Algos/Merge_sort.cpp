#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(log(n));
// Space complexity : O(n);
void merger(int arr[],int l,int mid,int h)
{
    int ln=mid-l+1;
    int rn=h-mid;
    int left[ln],right[rn];
    int k=l;
    for(int i=0;i<ln;i++)
    {
        left[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<rn;i++)
    {
        right[i]=arr[k];
        k++;
    }
    k=l;
    int ind1=0,ind2=0;
    while(ind1<ln && ind2<rn)
    {
        if(left[ind1]<right[ind2])
        {
            arr[k]=left[ind1];
            k++,ind1++;
        }
        else
        {
            arr[k]=right[ind2];
            k++,ind2++;
        }
    }
    while(ind1<ln)
    {
        arr[k]=left[ind1];
        k++,ind1++;
    }
    while(ind2<rn)
    {
        arr[k]=right[ind2];
        k++,ind2++;
    }
}
void mergesort(int arr[],int l, int h)
{
    if(l>=h) return;
    int mid=(l+h)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,h);
    merger(arr,l,mid,h);
    return;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

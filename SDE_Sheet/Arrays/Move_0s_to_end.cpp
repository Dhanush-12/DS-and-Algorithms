#include<bits/stdc++.h>
using namespace std;
void solve(int n, vector<int> &arr)
{
    int i=0,j=0;
    while(i<n)
    {
        while(arr[i] && arr[j] && i<n && j<n) i++,j++;
        while(arr[i]==0 && i<n) i++;
        while(arr[j] && j<n) j++;
        if(i<n)
        {
            swap(arr[i],arr[j]);
        }
    }
}
void moveZeroes(vector<int>& arr) 
{
        int ind=0;
		int n=arr.size();
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]!=0)
	        {
	            arr[ind]=arr[i];
	            ind++;
	        }
	    }
	    for(int i=ind;i<n;i++)
	    {
	        arr[i]=0;
	    }
}
vector<int> moveZeros(int n, vector<int> arr) {
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(arr[j]==0)
        {
            if(arr[i])
            {
                swap(arr[i],arr[j]);
                j++;
            }
        }
        else
        {
            j++;
        }
    }
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(n,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

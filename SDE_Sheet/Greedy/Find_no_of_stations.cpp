#include<bits/stdc++.h>
using namespace std;
// Time complexity O(2*(nlog(n)+n));
int findPlatform(int arr[], int dep[], int n)
{
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int p=1,ans=1;
    	int i=1,j=0;
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        p++;
    	        i++;
    	    }
    	    else if(arr[i]>dep[j])
    	    {
    	        p--;
    	        j++;
    	    }
    	    ans=max(ans,p);
    	}
    	return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n],dep[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>dep[i];
    cout<<findPlatform(arr,dep,n)<<endl;
}

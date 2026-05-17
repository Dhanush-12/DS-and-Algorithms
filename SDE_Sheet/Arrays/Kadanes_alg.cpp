#include<bits/stdc++.h>
using namespace std;
int brute(int arr[],int n)
{
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            ans=max(ans,sum);
        }
    }
    return ans;
}
int kadanes(int arr[],int n)
{
    int sum=0,start,maxi=INT_MIN,ansstart,ansend;
    for(int i=0;i<n;i++)
    {
        if(sum==0) start=i;
        sum+=arr[i];
        //cout<<sum<<" "<<maxi<<endl;
        if(maxi<sum)
        {
            maxi=sum;
            ansstart=start,ansend=i;
        }
        if(sum<0) sum=0;
    }
    if(maxi==INT_MIN)
    {
        cout<<"There is no maximum subarray"<<endl;
        return maxi;
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<brute(arr,n)<<endl;
    cout<<kadanes(arr,n)<<endl;
}

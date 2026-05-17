#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
int solve(int n,vector<int>&arr)
{
    vector<int>help(n,1);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            help[i]=help[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(help[i]>help[i+1])
        {
            help[i]=max(help[i],help[i+1]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=help[i];
    }
    return ans;
}
int optimal(int n,vector<int>&arr)
{
      int left[n];
        left[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1;
        }
        int curr=1,right=1,sum=max(left[n-1],1);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1])
                curr=right+1;
            else
                curr=1;
            right=curr; // right is updated outside if else
            sum+=max(left[i],curr);
        }
        return sum;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n,arr)<<endl;
}

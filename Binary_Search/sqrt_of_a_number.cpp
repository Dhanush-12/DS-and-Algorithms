#include<bits/stdc++.h>
#define nl endl
using namespace std;
int floor_of_sqrt(int n)
{
    int low=1,high=n;
    int mid,ans=0;
    while(low<=high)
    {
        mid=(low+(high-low)/2);
        if(mid*mid<=n)
        {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<floor_of_sqrt(n)<<endl;
}

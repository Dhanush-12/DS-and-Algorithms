#include<bits/stdc++.h>
#define ll long long
#define nl endl
using namespace std;
int nth_root_of_m(int n,int m)
{
    int low=1,high=m;
    while(low<=high)
    {
        int mid=(low+high)/2;
        ll ans=1;
        for(int i=0;i<n;i++)
        {
            ans*=mid;
            if(ans>m)
            {
                high=mid-1;
                break;
            }
        }
        if(ans==m) return mid;
        else if(ans<m) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{
    //while(1){
    int n,m;
    cin>>n>>m;
    cout<<nth_root_of_m(n,m)<<endl;
    //}
}

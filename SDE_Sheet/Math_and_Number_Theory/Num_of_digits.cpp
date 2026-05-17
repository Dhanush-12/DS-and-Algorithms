#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Time complexity : O(log(n))
int no_of_digits(ll n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    int ans=no_of_digits(n);
    cout<<ans<<endl;
    cout<<(int)(log10(n)+1)<<endl; // Time Complexity : O(1);
}

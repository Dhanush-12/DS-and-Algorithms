#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(r-l+1);
int bruteforce(int l,int r)
{
    int ans=0;
    for(int i=l;i<=r;i++) ans^=i;
    return ans;
}
// Time complexity : O(1)
int helper(int n)
{
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}
int optimal(int l,int r)
{
    return helper(r)^helper(l-1);
}
int main()
{
    int l,r;
    cin>>l>>r;
    cout<<bruteforce(l,r)<<endl;
    cout<<optimal(l,r)<<endl;
}

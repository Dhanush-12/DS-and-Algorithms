#include<bits/stdc++.h>
using namespace std;
// Time complecity : O(n);
int bruteforce(int n,int m)
{
    int cnt=0,sum=0;
    while(sum+m<=n)
    {
        sum+=m;
        cnt++;
    }
    return cnt;
}
// Time complexty : O(log2(n) * log2(n))
int optimal(int n,int m)
{
    int ans=0;
    int sign=0;
    if((n>=0 && m<0) || (n<0 && m>0)) sign=1;
    while(n>=m)
    {
        int cnt=0;
        while(n>=(m<<(cnt+1)))
        {
            cnt++;
        }
        ans+=(1<<cnt);
        n-=(m*(1<<cnt));
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<bruteforce(n,m)<<endl;
    cout<<optimal(n,m)<<endl;
}

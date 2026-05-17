#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int binexpo(int n,int p)
{
    if(n==0) return 0;
    if(p==0) return 1;

    if(p%2)
    {
        return n*binexpo(n,p-1);
    }
    else
    {
        return binexpo(n*n,p/2);
    }
    // time complexity:: O(log p);
    // space complexity:: O(1);
}
//using bit manpulation
long long binexpo1(int n,int p)
{
    long long res=1;
    while(p>0)
    {
        if(p&1)
        {
            res=res*n;
        }
        n=n*n;
        p>>=1;
    }
    return res;
    // time complexity:: O(log p);
    // space complexity:: O(1);
    // faster than the above approach cause we are using bit manipulation;
}
// handling the large testcases with modulus.
long long binexpo2(int n,int p)
{
    if(n==0) return 0;
    if(p==0) return 1;
    long long res=1;
    while(p>0)
    {
        if(p&1)
        {
            res=(res%MOD)*n%MOD;
        }
        n=(n*n)%MOD;
        p>>=1;
    }
    return res;
    // this method is for handling the larger testcases by reducing the computation to mod 1e9+7;
    // time complexity:: O(log p);
    // space complexity:: O(1);
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<binexpo2(n,p)<<endl;
}

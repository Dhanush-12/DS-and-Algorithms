#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(sqrt(n));
bool isprime(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(isprime(n))
    {
        cout<<"IS PRIME"<<endl;
    }
    else
    {
        cout<<"NOT PRIME"<<endl;
    }
    return 0;
}
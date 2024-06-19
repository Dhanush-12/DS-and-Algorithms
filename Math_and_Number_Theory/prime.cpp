#include<bits/stdc++.h>
using namespace std;
void seive_of_erathosthenes(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            for(int p=i*i;p<=n;p+=i)
            {
                prime[p]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            cout<<i<<" ";
        }
    }
}
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
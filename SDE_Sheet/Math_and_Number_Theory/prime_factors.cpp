#include <iostream>
#include <math.h>
using namespace std;
int primefactors(int n)
{
    int maxi=0;
   for(int i=2;i<=(sqrt(n));i++)
   {
       if(n%i==0)
       {
           cout<<i<<" ";
           maxi=max(maxi,i);
           while(n%i==0)
           {
               n/=i;
           }
       }
   }
   if(n!=1)
   {
       cout<<n<<" ";
       maxi=n;
   }
   return maxi;
}
// T(n) = (root(n) * (log(n)));
int main() {
   int n;
   cin>>n;
   cout<<"The prime factors of "<<n<<" are:"<<endl;
   int ans=primefactors(n);
   cout<<endl;
   cout<<"The largest prime factor of: "<<n<<" is: "<<ans<<endl;
}

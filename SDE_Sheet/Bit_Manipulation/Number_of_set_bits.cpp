#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(number of set bits)
int optimal(int n)
{
    int cnt=0;
    while(n)
    {
        cnt++;
        n=(n&(n-1));
    }
    return cnt;
}
// Time complexity : O(log(n));
int countsetbits(int n)
{
   int cnt=0;
   while(n)
   {
       if(n&1) cnt++;
       n>>=1;
   }
   return cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<optimal(n)<<endl;
    /* built in function is:
    cout<<__builtin_popcount(n)<<end;*/
}
// 13 - 1101
// 0 - based indexing from the right sides

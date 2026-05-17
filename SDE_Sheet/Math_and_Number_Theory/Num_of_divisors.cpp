#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(sqrt(n))
int count(int n)
{
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                cnt++;
            }
            else
            {
                cnt+=2;
            }
        }
    }
    return cnt;
}
int sumofdivisors(int n)
{
    int sum=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                sum+=i;
            }
            else
            {
                sum+=(i+(n/i));
            }
        }
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<count(n)<<endl;
}

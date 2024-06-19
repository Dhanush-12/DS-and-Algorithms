#include<bits/stdc++.h>
using namespace std;
void gcd1(int a,int b)
{
    while(a>0 && b>0)
    {
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) cout<<b<<endl;
    else cout<<a<<endl;
}
int gcd2(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd2(b,a%b);
}
int main()
{
    int n1,n2,ans;
    cin>>n1>>n2;
    for(int i=min(n1,n2);i>=1;i--)
    {
        if(n1%i==0 && n2%i==0)
        {
            ans=i;
            break;
        }
    }
    cout<<"The gcd is: "<<ans<<endl;//O(min(n1,n2));
    cout<<"The gcd is: ";
    gcd1(n1,n2);// O(long(min(n1,n2)));
    cout<<"The gcd is: ";
    cout<<gcd2(n1,n2)<<endl;// O(log(min(n1,n2)));
    cout<<"The LCM is: "<<(n1*n2)/ans<<endl;
}

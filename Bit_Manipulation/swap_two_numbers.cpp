#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(1);
void swapusingbits(int &a,int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
int main()
{
    int a,b;
    cin>>a>>b;
    swapusingbits(a,b);
    cout<<a<<" "<<b<<endl;
}

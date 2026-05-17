#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(1);
bool ispow(int n)
{
    return !(n&(n-1));
}
void lastsetbit(int &n)
{
    n = n&(n-1);
}
int main()
{
    int n;
    cin>>n;
    if(ispow(n))
    {
        cout<<"It is power of 2"<<endl;
    }
    else cout<<"It is not a power of 2"<<endl;
    lastsetbit(n);
    cout<<n<<endl;
}
// 13 - 1101
// 0 - based indexing from the right sides

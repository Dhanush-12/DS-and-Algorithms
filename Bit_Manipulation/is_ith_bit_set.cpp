#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(1);
bool isset(int n,int k)
{
    return n&(1<<k);
    // or
    return (n>>k)&1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    if(isset(n,k))
    {
        cout<<"set"<<endl;
    }
    else
    {
        cout<<"Not set"<<endl;
    }
}
// 13 - 1101
// 0 - based indexing from the right sides

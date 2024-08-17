#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(1);
void setithbit(int &n,int k)
{
    n = n|(1<<k);
}
void clearithbit(int &n,int k)
{
    n = n & (~(1<<k));
}
void toggleithbit(int &n,int k)
{
    n = n^(1<<k);
}
int main()
{
    int n,k;
    cin>>n>>k;
    setithbit(n,k);
    cout<<n<<endl;
    clearithbit(n,k);
    cout<<n<<endl;
    toggleithbit(n,k);
    cout<<n<<endl;
}
// 13 - 1101
// 0 - based indexing from the right sides

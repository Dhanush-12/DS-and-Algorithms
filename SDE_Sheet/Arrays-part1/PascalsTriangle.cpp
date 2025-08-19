#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// This function is used when we are asked to find a specific element of n row and r column
// Time Complexity: O(n);
// Space Complexity: O(1);
int anypascalsTriangleNumber(int n,int r) // Pass n-1, r-1 while calling this function
{
    ll ans=1;
    for(int i=0;i<r;i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
// This function is used when we are asked to print the nth row in the Pascal's Triangle
// Time Complexity: O(n*r)
// Space Complexity: O(1)
void bruteforce_pascalsTriangleRow(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<anypascalsTriangleNumber(n-1,i-1)<<" ";
    }
    cout<<endl;
}
// Time Complexity: O(n);
// Space Complexity: O(1)
void optimal_pascalsTriangleRow(int n)
{
    ll ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++)
    {
        ans*=(n-i);
        ans/=i;
        cout<<ans<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,r;
    cin>>n>>r;
    cout<<"The number at the given coordinate in the pascal's triangle is : "<<anypascalsTriangleNumber(n-1,r-1)<<endl;
    cout<<"Pascals row using bruteforce approach: "<<endl;
    bruteforce_pascalsTriangleRow(n);
    optimal_pascalsTriangleRow(n);
}
/*

*/

#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define sp(x, y) fixed << setprecision(x) << y
#define mod (int)(1e9 + 7)
#define nl endl
using namespace std;
// Generate a matric of size n*n which has the numbers in range 1 - n*n and the adjacent cells should not have adjacent numbers
void accepted()
{
    int n;
    cin >> n;
    int k=n*n;
    if(n==1)
    {
        cout<<1<<nl;
        return;
    }
    if(n==2)
    {
        cout<<-1<<nl;
        return;
    }
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        if(i&1)
        {
            cout<<i<<" ";
            cnt++;
            if(cnt==n) 
            {
                cnt=0;
                cout<<nl;
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(i%2==0)
        {
            cout<<i<<" ";
            cnt++;
            if(cnt==n) 
            {
                cnt=0;
                cout<<nl;
            }
        }
    }
}
int main()
{
    fastread();
    int t=1;
    cin>>t;
    while(t--)
    {
        accepted();
    }
    return 0;
}
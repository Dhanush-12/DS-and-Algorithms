#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
bool solve(int n,vector<int>&bills)
{
    int f=0,ten=0;
    for(int i=0;i<n;i++)
    {
        if(bills[i]==5)
        {
            f++;
        }
        else if(bills[i]==10)
        {
            if(f==0) return false;
            f--;
            ten++;
        }
        else
        {
            if(ten & f)
            {
                ten--,f--;
            }
            else if(f>=3)
            {
                f-=3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int>bills(n);
    for(int i=0;i<n;i++) cin>>bills[i];
    cout<<solve(n,bills)<<endl;
}

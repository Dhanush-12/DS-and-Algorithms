#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n);
int solve(string str)
{
    int n=(int)(str.size());
    int mini=0,maxi=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            mini=mini+1;
            maxi=maxi+1;
        }
        else if(str[i]==')')
        {
            mini-=1;
            maxi-=1;
        }
        else
        {
            mini-=1;
            maxi+=1;
        }
        if(mini<0)
            mini=0;
        if(maxi<0) return false;
    }
    return mini==0;
}
int main()
{
    string str;
    cin>>str;
    cout<<solve(str)<<endl;
}

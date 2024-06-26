#include<bits/stdc++.h>
using namespace std;
string dectobin(int n)
{
    string ans;
    while(n)
    {
        if(n&1)
        {
            ans+='1';
        }
        else
        {
            ans+='0';
        }
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string dectobin_inbuilt(int n)
{
    string ans=bitset<32>(n).to_string();
    return ans;
}
int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    string ans=dectobin(n);
    string ans1=dectobin_inbuilt(n);
    cout<<ans<<endl;
    cout<<ans1<<endl;
}

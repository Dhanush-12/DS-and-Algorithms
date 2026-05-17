#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(log2(n));
string convert(int n)
{
    string ans="";
    while(n)
    {
        if(n&1) ans+='1';
        else ans+='0';
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int convert2dec(string str)
{
    int ans=0,pw=1;
    int n=(int)(str.size());
    for(int i=n-1;i>=0;i--)
    {
        ans=ans+(str[i]-'0')*pw;
        pw*=2;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    string str=bitset<32>(n).to_string();
    cout<<"Builtin function says : ";
    cout<<str<<endl;
    str=convert(n);
    cout<<"My function says : ";
    cout<<str<<endl;
    int ans=convert2dec(str);
    cout<<"My function says : ";
    cout<<ans<<endl;
    ans=stoi(str,0,2);
    cout<<"Builtin Function says : ";
    cout<<ans<<endl;
}

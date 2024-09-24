#include<bits/stdc++.h>
using namespace std;
// Time complexity : O(3*n + k)
string remove_k_digits(int k,string str)
{
    stack<char>s;
    int n=(int)(str.size());
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && k>0 && (s.top()-'0')>(str[i]-'0'))
        {
            s.pop();
            k--;
        }
        s.push(str[i]);
    }
    while(k>0)
    {
        s.pop();
        k--;
    }
    if(s.empty())
    {
        return "0";
    }
    string ans;
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    while(ans.size() && ans.back()=='0')
    {
        ans.pop_back();
    }
    if(ans.empty())
    {
        return "0";
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    string ans=remove_k_digits(k,str);
    cout<<ans<<endl;
}
/*
1432219
3
*/

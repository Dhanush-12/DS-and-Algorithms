#include<bits/stdc++.h>
using namespace std;
int priority(char ch)
{
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return -1;
}
// Time complexity : O(n);
string infix_to_postfix(string str)
{
    int n=(int)str.size();
    string ans;
    stack<char>s;
    int i=0;
    while(i<n)
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9'))
        {
            ans+=str[i];
        }
        else if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else  if(str[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && priority(str[i])<=priority(s.top()))
            {
                ans+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        i++;
    }
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    string ans=infix_to_postfix(str);
    cout<<ans<<endl;
}

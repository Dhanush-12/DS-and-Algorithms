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
string postfix_to_infix(string str)
{
    int n=(int)str.size();
    int i=0;
    stack<string>s;
    while(i<n)
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9'))
        {
            string temp;
            temp+=str[i];
            s.push(temp);
        }
        else
        {
            string t1=s.top();
            s.pop();
            string t2=s.top();
            s.pop();
            string temp;
            temp+='('+t2+str[i]+t1+')';
            s.push(temp);
        }
        i++;
    }
    return s.top();
}
int main()
{
    string str;
    cin>>str;
    string ans=postfix_to_infix(str);
    cout<<ans<<endl;
}

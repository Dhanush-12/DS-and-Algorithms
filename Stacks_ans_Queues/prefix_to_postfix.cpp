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
string prefix_to_postfix(string str)
{
    int n=(int)str.size();
    stack<string>s;
    int i=n-1;
    while(i>=0)
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
            temp+=t1+t2+str[i];
            s.push(temp);
        }
        i--;
    }
    return s.top();
}
int main()
{
    string str;
    cin>>str;
    string ans=prefix_to_postfix(str);
    cout<<ans<<endl;
}

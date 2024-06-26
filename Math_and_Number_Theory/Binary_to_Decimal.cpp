#include<bits/stdc++.h>
using namespace std;
int bintodec(string str)
{
    int ans=0;
    int n=(int)(str.size());
    int base=1;
    for(int i=n-1;i>=0;i--)
    {
        ans=ans+base*(str[i]-'0');
        base*=2;
    }
    return ans;
}
int bintodec_inbuilt(string str)
{
    int n=stoi(str,0,2);
    return n;
}
int main()
{
    string str;
    cin>>str;
    int n=bintodec(str);
    int n1=bintodec_inbuilt(str);
    cout<<n<<endl;
    cout<<n1<<endl;
}

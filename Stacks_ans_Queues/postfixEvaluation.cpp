#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isOperator(string &str)
    {
        return str.size()==1 && (str[0]=='+' || str[0]=='-' || str[0]=='*' || str[0]=='/' || str[0]=='^');
    }
    int powerHelper(int n, int p)
    {
        int ans=1;

        while(p>0)
        {
            if(p%2==1) ans*=n;
            n*=n;
            p/=2;
        }

        return ans;
    }
    int divisionHelper(int a, int b)
    {
        int p = a/b;
        int rem = a%b;
        if(rem && ((a<0) ^ (b<0)))
        {
            p-=1;
        }
        return p;
    }
    int calculateResult(int n1, int n2, char ch)
    {
        if(ch == '+')
        {
            return n1+n2;
        }
        else if(ch == '-')
        {
            return n1-n2;
        }
        else if(ch == '*')
        {
            return n1*n2;
        }
        else if(ch == '/')
        {
            return divisionHelper(n1, n2);
        }
        else
        {
            return powerHelper(n1,n2);
        }
    }
  public:
    int evaluatePostfix(vector<string>& arr) {
        int n=(int)arr.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            string str=arr[i];
            if(isOperator(str))
            {
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                int res = calculateResult(num1, num2, str[0]);
                s.push(res);
            }
            else
            {
                int num=stoi(str);
                s.push(num);
            }
        }
        return s.top();
    }
};
int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    Solution s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<s.evaluatePostfix(arr)<<endl;
}

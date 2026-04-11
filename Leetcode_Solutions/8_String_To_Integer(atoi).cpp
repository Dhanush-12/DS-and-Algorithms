#include<bits/stdc++.h>
using namespace std;
class Solution {
    const int MAXI = 2147483647;
    const int MINI = -2147483648;
    bool isDigit(char ch)
    {
        return (ch>='0' && ch<='9');
    }
public:
    int myAtoi(string s) {
        int n = (int)s.size();
        long long ans = 0;
        int ind = 0;
        bool isneg = false;
        bool exceeded = false;
        while(ind < n && (s[ind] == ' ')) ind++;
        if(s[ind] == '-' || s[ind] == '+')
        {
            if(s[ind] == '-') isneg = true;
            ind++;
        }
        while(ind < n && (s[ind] == '0')) ind++;
        while(ind<n && isDigit(s[ind]))
        {
            ans = (ans*10ll)+(s[ind]-'0');
            if(ans > MAXI)
            {
                exceeded = true;
                ans = MAXI;
                break;
            }
            ind++;
        }
        return (isneg) ? (exceeded ? MINI : -ans) : ans;
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.myAtoi(str)<<endl;
}

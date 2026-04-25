#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isMatch(char a, char b)
    {
        return a == '(' ? b==')' : a == '{' ? b=='}' : b==']';
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                else if(!isMatch(st.top(), s[i])) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.isValid(str)<<endl;
}

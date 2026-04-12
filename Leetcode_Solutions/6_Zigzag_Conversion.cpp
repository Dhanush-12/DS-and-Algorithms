#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int n = (int)s.size();
        if(numRows == 1) return s;
        string ans = "";
        int steps = 2*(numRows-1);
        int substeps = steps - 2;
        for(int i=0;i<numRows;i++)
        {
            int st = i;
            while(st < n)
            {
                ans += s[st];
                if(i > 0 && i < numRows-1)
                {
                    if(st+substeps < n) ans += s[st+substeps];
                }
                st += steps;
            }
            if(i > 0) substeps -= 2;
        }
        return ans;
    }
};
int main()
{
    string str;
    int n;
    cin>>str>>n;
    Solution s;
    cout<<s.convert(str, n)<<endl;
}

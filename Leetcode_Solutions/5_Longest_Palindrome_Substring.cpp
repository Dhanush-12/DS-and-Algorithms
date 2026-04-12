#include<bits/stdc++.h>
using namespace std;
class Solution {
    int expand(string &s, int left, int right, int n)
    {
        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();

        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++)
        {
            int odd = expand(s, i, i, n);
            int even = expand(s, i, i+1, n);

            int maxi = max(odd, even);

            if(maxi > end-start)
            {
                start = i - (maxi-1)/2;
                end = i + maxi/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.longestPalindrome(str)<<endl;
}

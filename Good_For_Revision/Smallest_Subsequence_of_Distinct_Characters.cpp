#include<bits/stdc++.h>
using namespace std;
/*
    Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
    Example 1:

    Input: s = "bcabc"
    Output: "abc"
    Example 2:

    Input: s = "cbacdcbc"
    Output: "acdb"
*/
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = (int)s.size();
        vector<int> last(26, -1);
        vector<bool> used(26, 0);
        for(int i=0;i<n;i++)
        {
            last[s[i]-'a'] = i;
        }
        string ans;
        for(int i=0;i<n;i++)
        {
            char current = s[i];
            int currIndex = current-'a';
            if(used[currIndex])
            {
                continue;
            }
            while(!ans.empty() && ans.back() > current && last[ans.back()-'a'] > i)
            {
                used[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(current);
            used[currIndex] = true;
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.smallestSubsequence(str)<<endl;
}

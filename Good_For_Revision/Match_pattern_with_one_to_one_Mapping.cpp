#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Given a dictionary of strings d[] and a string pat, find all strings in d[] that
    follow the same character pattern as pat. A string matches pat if there exists a one-to-one
    mapping between the characters of pat and the characters of the string. Return all matching
    strings.

    Input: d[] = ["abb", "abc", "xyz", "xyy"], pat  = "foo"
    Output: ["abb", "xyy"]
    Explanation: "abb" and "xyy" match the pattern because the second and third characters are
    the same, just like in "foo"

    Input: d[] = ["aab", "mno", "xyx", "aba", "ccc"], pat = "xyx"
    Output: ["xyx", "aba"]
    Explanation: "xyx" and "aba" match the pattern because the first and third characters are
    the same, while the second character is different. The mapping is consistent and one-to-one.
*/
class Solution {
  public:
    vector<string> matchingStrings(vector<string>& d, string& pat) {
        int n = (int)d.size();
        vector<string> ans;
        for(string& now : d)
        {
            if(now.size() != pat.size()) continue;

            unordered_map<char,char> dToP;
            unordered_map<char,char> pToD;
            bool ok = true;

            for(int i=0;i<now.size();i++)
            {
                if(dToP.find(now[i]) != dToP.end())
                {
                    if(pat[i] != dToP[now[i]])
                    {
                        ok = false;
                        break;
                    }
                }
                if(pToD.find(pat[i]) != pToD.end())
                {
                    if(now[i] != pToD[pat[i]])
                    {
                        ok = false;
                        break;
                    }
                }
                dToP[now[i]] = pat[i];
                pToD[pat[i]] = now[i];
            }
            if(ok)
            {
                ans.push_back(now);
            }
        }
        return ans;
    }
};
int main() 
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    string pat;
    cin>>pat;
    Solution s;
    vector<string> ans = s.matchingStrings(arr, pat);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
4
abb abc xyz xyy
foo

5
aab mno xyx aba ccc
xyx
*/
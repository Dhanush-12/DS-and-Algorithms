#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a string s, find the length of the longest substring without duplicate
    characters.

    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are
    also correct answers.
    
    Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    
    Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        int freq[26] = {0};
        int left = 0 ;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
            while(left < i && freq[s[i]-'a'] > 1)
            {
                freq[s[left]-'a'] -= 1;
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
}
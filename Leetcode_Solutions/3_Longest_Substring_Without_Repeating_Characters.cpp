#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        int ans=0;
        unordered_map<char,int>mp;
        int left=0;
        for(int right=0;right<n;right++)
        {
            mp[s[right]]++;
            while(left<right && (mp[s[right]] > 1))
            {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
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

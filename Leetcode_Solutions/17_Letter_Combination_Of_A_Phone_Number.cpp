#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans = {""};
        string phone[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        for(char digit : digits)
        {
            vector<string> new_ans;
            for(string ch : ans)
            {
                for(char letter : phone[digit-'2'])
                {
                    new_ans.push_back(ch+letter);
                }
            }
            ans = new_ans;
        }
        return ans;
    }
};
int main()
{
    string digits;
    cin>>digits;
    Solution s;
    vector<string> ans = s.letterCombinations(digits);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

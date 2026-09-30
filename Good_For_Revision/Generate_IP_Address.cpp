#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Given a string s containing only digits, your task is to restore it by
    returning all possible valid IP address combinations. You can return your answer in
    any order.

    A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers
    from 0-255(inclusive).

    Note: The numbers cannot be 0 prefixed unless they are 0. For example, 1.1.2.11 and
    0.11.21.1 are valid IP addresses while 01.1.2.11 and 00.11.21.1 are not.
    If there are no possible valid IP address return an empty list. The driver code will
    print -1 in this case.

    Input: s = “255678166”
    Output: [“25.56.78.166”, “255.6.78.166”, “255.67.8.166”, “255.67.81.66”]
    Explanation: These are the only valid possible IP addresses.

    Input: s = “25505011535”
    Output: []
    Explanation: We cannot generate a valid IP address with this string.
*/
class Solution {
    bool isValid(string &str)
    {
        if(str[0] == '0' && str.size() > 1)
        {
            return false;
        }

        int val = stoi(str);
        return val <= 255;
    }
    void generateIpHelper(const string &str, int ind, string curr, int cnt, vector<string> &ans)
    {
        if(ind >= str.size()) return;

        if(cnt == 3)
        {
            string last = str.substr(ind);
            if(last.size() <= 3 && isValid(last))
            {
                ans.push_back(curr + last);
            }
            return;
        }
        string segment = "";
        for(int i=ind;i<min(ind+3, (int)str.size());i++)
        {
            segment += str[i];


            if(isValid(segment)) {
                generateIpHelper(str, i+1, curr+segment+'.', cnt+1, ans);
            }
        }
    }
  public:
    vector<string> generateIp(string &s) {
        vector<string> ans;
        generateIpHelper(s, 0, "", 0, ans);
        return ans;
    }
};
int main() 
{
    string str;
    cin>>str;
    Solution s;
    vector<string> ans = s.generateIp(str);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
}
#include <bits/stdc++.h>
using namespace std;

/*
    Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing 
    order(from left to right).
    Input: n = 1
    Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    
    Input: n = 2
    Output: [12, 13, 14, 15, 16, 17, 18, 19, 23....79, 89]
*/

class Solution {
    void solve(string str, vector<int> &ans, int n)
    {
        if(str.size() == n)
        {
            ans.push_back(stoi(str));
            return;
        }

        for(char ch = '1'; ch <= '9'; ch++)
        {
            if(!str.empty() && str.back() >= ch) continue;
            str.push_back(ch);
            solve(str, ans, n);
            str.pop_back();
        }
        return;
    }
  public:
    vector<int> increasingNumbers(int n) {
        if(n == 1)
        {
            vector<int>ans;
            for(int i=0;i<=9;i++) ans.push_back(i);
            return ans;
        }
        if(n == 9)
        {
            return {123456789};
        }
        if(n > 9) return {};
        vector<int> ans;
        solve("", ans, n);
        return ans;
    }
};
int main() {
    int n;
    cin>>n;
    Solution s;
    vector<int> ans = s.increasingNumbers(n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

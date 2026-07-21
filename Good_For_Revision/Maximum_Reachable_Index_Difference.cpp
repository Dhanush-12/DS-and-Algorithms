#include<bits/stdc++.h>
using namespace std;
/*
    Given a string s containing lowercase English alphabets.

    Start from any index containing the character 'a' and perform jump operations.
    In each jump operation, move to any index on the right side whose character is the immediate next letter of the current character
    in the alphabet (i.e., 'a' to 'b', 'b' to 'c', 'c' to 'd', and so on). 
    Continue performing jumps until no further jump is possible.
    Find the maximum possible difference between the starting index and the ending index. If it is not possible to choose a starting
    index, return -1.

    Examples :

    Input: s = "aaabcb"
    Output: 5
    Explanation: Start at index 0 ('a'), jump to index 5 ('b'). Difference = 5 - 0 = 5.
*/
class Solution {
    const int INF = 1e9;
  public:
    int maxIndexDifference(string &s) {
        int n = (int)s.size();
        vector<int> start(26, INF);
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            int curr = s[i]-'a';
            if(curr == 0)
            {
                start[0] = min(start[0], i);
                ans = max(ans, 0);
            }
            else
            {
                int previous = curr-1;
                if(start[previous] != INF)
                {
                    start[curr] = min(start[curr], start[previous]);
                    ans = max(ans, i-start[curr]);
                }
            }
        }
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    string str;
    Solution s;
    while(t--)
    {
        cin>>str;
        cout<<s.maxIndexDifference(str)<<endl;
    }
}
/*
6
aaabcb
xynjir
abcbzzd
biyazbpstgc
hahdayabamcde
mvlaugbenicydaf

5
-1
6
7
11
9
*/

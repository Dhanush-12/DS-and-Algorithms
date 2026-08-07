#include<bits/stdc++.h>
using namespace std;
/*
    Problem:Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once.
    Find out the total number of ways in which friends can remain single or can be paired up.

    Examples :

    Input: n = 3
    Output: 4
*/
class Solution {
  public:
    int countFriendsPairings(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]+((i-1)*dp[i-2]);
        }
        return dp[n];
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.countFriendsPairings(n)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
/*
    Problem : Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can be completed on the i-th
    day by performing a high-effort task and a low-effort task, respectively.

    For each day, you may choose exactly one of the following:

    Perform no task.
    Perform a low-effort task.
    Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.
    Return the maximum total number of tasks that can be completed over all days.

    Examples:

    Input: h[] = [2, 8, 1], l[] = [1, 2, 1]
    Output: 9
    Explanation: Pick the high-effort task on day 1 and the low-effort task on day 2. Total = 8 + 1 = 9.
*/
class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = (int)h.size();
        vector<int> dp(n, 0);
        int last = 0;
        if(h[0] > l[0])
        {
            dp[0] = h[0];
        }
        else dp[0] = l[0];
        if(h[0] || l[0]) last = 1;
        for(int i=1;i<n;i++)
        {
            if(h[i] == 0 && l[i] == 0)
            {
                last = 0;
                continue;
            }
            if(h[i] > l[i])
            {
                if(last)
                {
                    if(i == 1)
                    {
                        dp[i] = max(h[i], dp[i-1]+l[i]);
                    }
                    else
                    {
                        dp[i] = max(dp[i-2]+h[i], dp[i-1]+l[i]);
                    }
                }
                else
                {
                    dp[i] += h[i];
                    last = 1;
                }
            }
            else
            {
                dp[i] = dp[i-1]+l[i];
            }
        }
        return dp[n-1];
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> h(n), l(n);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>l[i];
    Solution s;
    cout<<s.maxTask(h, l)<<endl;
}
/*
3
2 8 1
1 2 1

5
3 6 8 7 6
1 5 4 5 3
*/

#include<bits/stdc++.h>
using namespace std;

/*

    Problem : You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where
    queries[i] = [li, ri].For each queries[i], extract the substring s[li..ri]. Then, perform the following:

    Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no
    non-zero digits, x = 0.Let sum be the sum of digits in x. The answer is x * sum. Return an array of integers answer where
    answer[i] is the answer to the ith query. Since the answers may be very large, return them modulo 109 + 7.

    Example 1:

    Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

    Output: [12340, 4, 9]

*/

const int mod = 1e9 + 7;
const int max_n = 100001;
long long pow10[max_n];
int init = []() {
    pow10[0] = 1;
    for(int i=1;i<max_n;i++) {
        pow10[i] = (pow10[i-1]*10)%mod;
    }
    return 0;
}();
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = (int)s.size();
        vector<int>sum(n+1, 0);
        vector<long long> x(n+1, 0);
        vector<int> cnt(n+1, 0);

        for(int i=0;i<n;i++)
        {
            int d = s[i] - '0';
            sum[i+1] = sum[i]+d;
            x[i+1] = (d > 0) ? (x[i]*10 + d) % mod : x[i];
            cnt[i+1] = cnt[i]+(d > 0);
        }
        int m = (int)queries.size();
        vector<int> ans(m, 0);
        for(int i=0;i<m;i++)
        {
            int l = queries[i][0];
            int r = queries[i][1]+1;
            int length = cnt[r]-cnt[l];
            long long val_x = (x[r]-x[l] * pow10[length]%mod + mod) % mod;
            long long val_sum = sum[r]-sum[l];
            ans[i] = (val_x*val_sum) % mod;
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
    vector<vector<int>> q(n, vector<int>(2, 0));
    for(int i=0;i<n;i++) cin>>q[i][0]>>q[i][1];
    Solution s;
    vector<int> ans=s.sumAndMultiply(str, q);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

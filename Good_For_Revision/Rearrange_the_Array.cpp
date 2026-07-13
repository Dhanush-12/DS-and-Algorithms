#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;

/*
    Problem : Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing
    all integers from 1 to n exactly once. The array b[] defines a rearrangement operation. During
    a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).
    We must do at least one operation on a[].
    Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: [1, 2, 3, ..., n] again.

    Note:  The answer can be large, so return the answer modulo 10^9+7.

    Examples:

    Input: b[] = [1, 2, 3]
    Output: 1
*/

class Solution {
    int __lcm(int a, int b)
    {
        return (a*b)/(__gcd(a, b));
    }
    int dfs(int u, vector<int>&b, vector<int> &vis)
    {
        if(vis[u]) return 0;

        vis[u] = 1;
        return 1 + dfs(b[u]-1, b, vis);
    }
  public:
    int minOperations(vector<int> &b) {
        int n = (int)b.size();
        vector<int> l;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            int cycleLength = dfs(i, b, vis);
            l.push_back(cycleLength);
        }
        int lcm = l[0];
        for(int i=1;i<l.size();i++)
        {
            lcm = __lcm(lcm, l[i]);
        }
        return lcm;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.minOperations(arr)<<endl;
}

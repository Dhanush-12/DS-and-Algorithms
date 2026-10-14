#include<bits/stdc++.h>
using namespace std;
/*
    Porblem: You are playing a game with n people standing in a circle, numbered from 1 to n.
    Starting from person 1, every kth person is eliminated in a circular fashion. The process
    continues until only one person remains.
    Given integers n and k, return the position (1-based index) of the person who will survive.

    Input: n = 5, k = 2
    Output: 3

    Input: n = 7, k = 3
    Output: 4
*/
class Solution {
  public:
    // Time Complexity: O(n*k)
    // Space Complexity: O(n);
    int josephus(int n, int k) {
        if(n == 1) return 1;
        vector<int> vis(n, 0);
        int limit = k;
        k %= n;
        vis[k] = 1;
        int covered = 1;
        int st = k;
        while(covered < n-1)
        {
            int start = 0;
            while(start < limit)
            {
                if(!vis[st])
                {
                    start++;
                    if(start == limit) break;
                }
                st = (st + 1) % n;
            }
            vis[st] = 1;
            covered += 1;
        }
        int end = -1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                end = i;
                break;
            }
        }
        if(end == 0) return n;
        return end;
    }

    // Recursion Approach
    // Time Complexity: O(n)
    // Space Complexity: O(n) (auxiliary space)
    int josephus(int n, int k) {
        if(n == 1) return 1;
        return (josephus(n-1, k) + k - 1) % n + 1;
    }

    //Iterative Approach
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int josephus(int n, int k) {
        int ans = 0;
        for(int i=2;i<=n;i++)
        {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    Solution s;
    cout<<s.josephus(n, k)<<endl;
}
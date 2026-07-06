#include<bits/stdc++.h>
using namespace std;

/*

    Given two sorted arrays of distinct integers in increasing order a[] and b[], which may have some common elements, find the
    maximum sum of a path from the beginning of any array to the end of any array. You may switch from one array to the other only
    at common elements.

    Note:  When switching, count the common element only once.

    Examples :

    Input: a[] = [2, 3, 7, 10, 12], b[] = [1, 5, 7, 8]
    Output: 35

*/
class Solution {
  public:
  // Time Complexity : O(n + m)
  // Space Complexity : O(1)
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int ans = 0;
        int asum = 0, bsum = 0;
        int n = (int)a.size();
        int m = (int)b.size();
        int i = n-1, j = m - 1;
        while(i >= 0 && j >= 0)
        {
            if(a[i] == b[j])
            {
                ans += max(asum, bsum);
                asum = a[i], bsum = b[j];
                i--,j--;
            }
            else if(a[i] > b[j])
            {
                asum += a[i];
                i--;
            }
            else
            {
                bsum += b[j];
                j--;
            }
        }
        while(i >= 0)
        {
            asum += a[i];
            i--;
        }
        while(j >= 0)
        {
            bsum += b[j];
            j--;
        }
        ans += max(asum, bsum);
        return ans;
    }
};
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    Solution s;
    cout<<s.maxPathSum(a, b)<<endl;
}

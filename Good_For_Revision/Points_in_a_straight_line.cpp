#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given two arrays x[] and y[], where the point (x[i], y[i]) represents a point
    on the Cartesian plane. Find the maximum number of points that lie on the same straight
    line.

    Examples:

    Input: x[] = [1, 2, 3], y[] = [1, 2, 3]
    Output: 3
    Explanation: The points in straight line are (1,1), (2,2) and (3,3).
*/
class Solution {
  public:
    int maxPoints(vector<int>& x, vector<int>& y) {
        int n = (int)x.size();
        
        if(n <= 2) return n;

        int ans = 1;

        for(int i=0;i<n;i++)
        {
            map<pair<ll, ll>, int> mp;
            int duplicates = 0;
            int maxCount = 0;

            for(int j=0;j<n;j++)
            {
                if(i == j) continue;
                ll dx = (ll)(x[j]-x[i]);
                ll dy = (ll)(y[j]-y[i]);

                if(dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                ll g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if(dx < 0  || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                mp[{dx, dy}]++;
                maxCount = max(maxCount, mp[{dx, dy}]);
            }

            ans = max(ans, maxCount+duplicates+1);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];
    Solution s;
    cout<<s.maxPoints(x, y)<<endl;
}
/*
6
1 3 5 4 2 1
1 2 3 1 3 4

5
1 2 3 4 5 
1 2 3 4 5
*/
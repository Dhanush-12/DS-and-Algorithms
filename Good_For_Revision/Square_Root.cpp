#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int floorSqrt(long long n) {
        long long low = 1, high = n-1;
        long long mid, ans = 1;
        while(low <= high)
        {
            mid = low + (high-low)/2ll;
            if((long long)mid*mid <= n)
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};
int main()
{
    long long n;
    cin>>n;
    Solution s;
    cout<<s.floorSqrt(n)<<endl;
}

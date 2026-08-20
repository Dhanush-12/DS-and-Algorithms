#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Time Complexity : O(sqrt(n))
    // Space Complexity : O(1)
    int sqrtFloor(long long n)
    {
        long long res = 1;

        while((long long)(res*res) <= n)
        {
            res++;
        }

        return res-1;
    }
    // Time Complexity : O(log(n))
    // Space Complexity : O(1)
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
    /*
    Let's say square root of n is x:
    => x = √n
    Squaring both the sides:
    => x2 =n
    Taking log on both the sides:
    => log(x2) = log(n)
    => 2 × log(x) = log(n)
    => log(x) = 1/2 × log(n)
    To isolate x, exponentiate both sides with base e:
    => x = e1/2 * log(n)
    x is the square root of n:
    So, √n = e1/2 × log(n)
    */
    // Time Complexity : O(1) used by pocket calculators
    // Space Complexity : O(1)
    int sqrtValue(int n)
    {
        int res = exp(0.5 * log(n));

        if((res+1)*(res+1) <= n) res++;

        return res;
    }
};
int main()
{
    long long n;
    cin>>n;
    Solution s;
    cout<<s.sqrtValue(n)<<endl;
}

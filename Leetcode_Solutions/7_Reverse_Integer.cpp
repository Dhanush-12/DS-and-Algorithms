#include<bits/stdc++.h>
using namespace std;
class Solution {
    const int MAXI = 2147483647;
    const int MINI = -2147483648;
public:
    int reverse(int x) {
        bool isNegitive = false;
        bool isOverloaded = false;
        if(x < 0)
        {
            isNegitive = true;
            if(x == MINI) return 0;
        }
        x = abs(x);
        int ans = 0;
        while(x > 0)
        {
            if(ans > (MAXI / 10)) return 0;
            ans = (ans * 10) + x % 10;
            x /= 10;
        }
        return isNegitive ? -ans : ans;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.reverse(n)<<endl;
}

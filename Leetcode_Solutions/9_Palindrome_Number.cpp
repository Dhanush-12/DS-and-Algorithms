#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int dummy = x;
        long long temp = 0;
        while(dummy > 0)
        {
            temp = (temp*10)+dummy%10;
            dummy /= 10;
        }
        return temp == x;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.isPalindrome(n)<<endl;
}

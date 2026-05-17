#include<bits/stdc++.h>
using namespace std;
int min_bits_to_goal(int n,int m)
{
    int ans=n^m;
    //return __builtin_popcount(ans);// Time complexity : O(log(n^m));
    int cnt=0;
    while(ans)
    {
        cnt++;
        ans=(ans&(ans-1));
    }
    return cnt; // Time complexiity : O(Number of set bits
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<min_bits_to_goal(n,m)<<endl;
}
// 13 - 1101
// 0 - based indexing from the right sides

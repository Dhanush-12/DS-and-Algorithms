#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
bool isPossible(string &s1,string &s2)
{
    if(s1.size() != s2.size()+1) return false;
    int i=0,j=0;
    while(i<s1.size())
    {
        if(s1[i]==s2[j])
        {
            i++,j++;
        }
        else
        {
            i++;
        }
    }
    return (i==s1.size() && j==s2.size());
}
// Function to find the length of longest string chain
// Time Complexity: O(n^2 + nLog(n))
// Space Complexity: O(n)
int longestStrChain(int n,vector<string>&arr)
{
    sort(arr.begin(),arr.end(),[&](string s1,string s2){
            return s1.size()<s2.size();
         });
    vector<int>dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(isPossible(arr[i],arr[j]) && 1+dp[j]>dp[i])
            {
                dp[i]=1+dp[j];
            }
        }
        if(dp[i] > maxi)
        {
            maxi=dp[i];
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<longestStrChain(n,arr)<<endl;
}


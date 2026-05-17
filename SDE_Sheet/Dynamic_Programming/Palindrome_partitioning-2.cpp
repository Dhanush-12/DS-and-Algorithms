#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
bool isPalindrome(int i,int j,string &str)
{
    while(i<j)
    {
        if(str[i] != str[j]) return false;
        i++,j--;
    }
    return true;
}
// Time Complexity: O(n^2) and Space Complexity: O(n^2)+O(n)
int recursion(int ind,int n,string &str)
{
    if(ind == n) return 0;
    int ans=INT_MAX;
    for(int j=ind;j<n;j++)
    {
        if(isPalindrome(ind,j,str))
        {
            int cost=1+recursion(j+1,n,str);
            ans=min(ans,cost);
        }
    }
    return ans;
}
// Time Complexity : O(n^2), Space Complexity: O(n)
int memorization(int ind,int n,string &str,vector<int>&dp)
{
    if(ind==n) return 0;
    if(dp[ind] != -1) return dp[ind];
    int ans=INT_MAX;
    for(int j=ind;j<n;j++)
    {
        if(isPalindrome(ind,j,str))
        {
            int cost=1+memorization(j+1,n,str,dp);
            ans=min(ans,cost);
        }
    }
    return dp[ind]=ans;
}
// Time Complexity : O(n^2), Space Complexity: O(n)
int tabulation(int n,string &str,vector<int>&dp)
{
    dp[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        int mincost=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(i,j,str))
            {
                int cost=1+dp[j+1];
                mincost=min(mincost,cost);
            }
        }
        dp[i]=mincost;
    }
    return dp[0]-1;
}
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<"Answer using recursion: "<<recursion(0,n,str)-1<<endl;
    vector<int>dp(n,-1);
    cout<<"Answer using memorization: "<<memorization(0,n,str,dp)-1<<endl;
    vector<int>dp1(n+1,0);
    cout<<"Answer using Tabulation: "<<tabulation(n,str,dp1)<<endl;
}
/*
13
bababcbadcede
*/

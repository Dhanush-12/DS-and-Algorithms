#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
// Find the Shortest Common SuperSequence of both the strings.(SCS is the string that contains both the given strings maintaining the order)
// Time Complexity: O(n*m) and Space Complexity: O(n*m);
string shortestCommonSuperSequence(int n,int m,string s,string t)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            ans+=s[i-1];
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans+=s[i-1];
            i--;
        }
        else
        {
            ans+=t[j-1];
            j--;
        }
    }
    while(i>0)
    {
        ans+=s[i-1];
        i--;
    }
    while(j>0)
    {
        ans+=t[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    cout<<"Answer using Tabulation: "<<shortestCommonSuperSequence(n,m,s,t)<<endl;
}

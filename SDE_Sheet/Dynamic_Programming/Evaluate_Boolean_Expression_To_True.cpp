#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Time Complexity: O(n^3) and Space Complexity: O(n^2)+O(n)
int recursion(int i,int j,int isTrue,string &str)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(isTrue)
        {
            return str[i]=='T';
        }
        else
        {
            return str[i]=='F';
        }
    }
    int ans=0;
    for(int ind=i+1;ind<=j-1;ind+=2)
    {
        int lT=recursion(i,ind-1,1,str);
        int lF=recursion(i,ind-1,0,str);
        int rT=recursion(ind+1,j,1,str);
        int rF=recursion(ind+1,j,0,str);

        if(str[ind]=='&')
        {
            if(isTrue) ans=(ans+(rT*lT));
            else ans=ans+(rT*lF)+(rF*lT)+(rF*lF);
        }
        else if(str[ind]=='|')
        {
            if(isTrue) ans=(ans+(lT*rT)+(lT*rF)+(lF*rT));
            else ans=ans+(rF*lF);
        }
        else
        {
            if(isTrue)
            {
                ans=(ans+(lT*rF)+(lF*rT));
            }
            else
            {
                ans=(ans+(lT*rT)+(lF*rF));
            }
        }
    }
    return ans;
}
// Time Complexity: O(n^3) and Space Complexity: O(n^2)
int memorization(int i,int j,int isTrue,string &str,vector<vector<vector<int>>>&dp)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(isTrue)
        {
            return str[i]=='T';
        }
        else
        {
            return str[i]=='F';
        }
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    int ans=0;
    for(int ind=i+1;ind<=j-1;ind+=2)
    {
        int lT=memorization(i,ind-1,1,str,dp);
        int lF=memorization(i,ind-1,0,str,dp);
        int rT=memorization(ind+1,j,1,str,dp);
        int rF=memorization(ind+1,j,0,str,dp);

        if(str[ind]=='&')
        {
            if(isTrue) ans=(ans+(rT*lT));
            else ans=ans+(rT*lF)+(rF*lT)+(rF*lF);
        }
        else if(str[ind]=='|')
        {
            if(isTrue) ans+=(lT*rT)+(lT*rF)+(lF*rT);
            else ans+=(rF*lF);
        }
        else
        {
            if(isTrue)
            {
                ans=(ans+(lT*rF)+(lF*rT));
            }
            else
            {
                ans=(ans+(lT*rT)+(lF*rF));
            }
        }
    }
    return dp[i][j][isTrue]=ans;
}
// Time Complexity ~~ o(N^3) and Space Complexity: O(n^2)
int tabulation(string &exp)
{
    int n=exp.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else
            {
                ll ways=0;
                for(ll ind=i+1;ind<=j-1;ind+=2)
                {
                    ll lt=dp[i][ind-1][1]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rf=dp[ind+1][j][0]%mod;
                    if(exp[ind]=='&')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}
int main()
{
    string str;
    cin>>str;
    int n=(int)str.size();
    cout<<"Answer using recursion: "<<recursion(0,n-1,1,str)<<endl;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    cout<<"Answer using memorization: "<<memorization(0,n-1,1,str,dp)<<endl;
    cout<<"Answer using tabulation: "<<tabulation(str)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
string longestCommonSubsequence(string &str1, string &str2)
{
    int n = (int)str1.size();
    int m = (int)str2.size();
    string ans = "";
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string str;
	int i=n,j=m;
	while(i>0 && j>0)
	{
       if(str1[i-1]==str2[j-1])
	   {
		  str+=str1[i-1];
		  i--,j--;
	   }
	   else if(dp[i-1][j]>dp[i][j-1])
	   {
		   i--;
	   }
	   else
	   {
		   j--;
	   }
	}
	reverse(str.begin(),str.end());
	return str;
}
int main()
{
    string str1, str2;
    cin>>str1>>str2;
    string ans = longestCommonSubsequence(str1, str2);
    cout<<ans<<endl;
}
/*
abcd
bdef
*/

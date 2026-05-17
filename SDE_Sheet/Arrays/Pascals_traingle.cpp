#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>pascalstriangle(int n)
{
    vector<vector<int>>ans;
    vector<int>temp;
    ans.push_back({1});
    ans.push_back({1,1});
    for(int i=2;i<n;i++)
    {
        vector<int>prev=ans[i-1];
        temp.push_back(1);
        for(int j=1;j<prev.size();j++)
        {
            temp.push_back(prev[j]+prev[j-1]);
        }
        temp.push_back(1);
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}
vector<int>generaterows(int row)
{
    int ans=1;
    vector<int>res;
    res.push_back(1);
    for(int col=1;col<row;col++)
    {
        ans*=(row-col);
        ans/=col;
        res.push_back(ans);
    }
    return res;
}
vector<vector<int>>pascalstriangle_optimal(int n)
{
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++)
    {
        vector<int>temp=generaterows(i);
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>ans=pascalstriangle_optimal(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

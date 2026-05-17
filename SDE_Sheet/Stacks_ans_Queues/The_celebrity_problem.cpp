#include<bits/stdc++.h>
using namespace std;
// Celebrity is the one who knows no one, but is known by everyone
// Time complexity : O(n*m)
int celebrity_problem_bruteforce(int n,vector<vector<int>>&arr)
{
    int knowme[n],iknow[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                knowme[j]++;
                iknow[i]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(knowme[i]==n-1 && iknow[i]==0)
        {
            return i;
        }
    }
    return -1;
}
// Time complexity : O(2*n)
int celebrity_problem_optimal(int n,vector<vector<int>>&arr)
{
    int top=0,down=n-1;
    while(top<down)
    {
        if(arr[top][down]==1)
        {
            top++;
        }
        else if(arr[down][top]==1)
        {
            down--;
        }
        else
        {
            top--;
            down--;
        }
    }
    //cout<<top<<" "<<down<<endl;
    if(top>down) return -1;
    for(int i=0;i<n;i++)
    {
        if(i==top) continue;
        if(arr[top][i]==0 && arr[i][top]==1)
        {
            continue;
        }
        else return -1;
    }
    return top;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<celebrity_problem_optimal(n,arr)<<endl;
}
/*
4
0 1 1 0
0 0 0 0
0 1 0 0
1 1 0 0
*/

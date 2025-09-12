#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Best Time to Buy and Sell Stock
int BestTimeToBuyAndSellStock(int n, vector<int>&arr)
{
    int ans=0;
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mini=min(mini,arr[i]);
        ans=max(ans, arr[i]-mini);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"After sorting: ";
    cout<<BestTimeToBuyAndSellStock(n,arr)<<endl;
}
/*
6
7 1 5 3 6 4
*/

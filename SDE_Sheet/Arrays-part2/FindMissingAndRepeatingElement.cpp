#include<bits/stdc++.h>
using namespace std;
//Given array N integers and all integers are between 1 and n where, one of those numbers is missing and one of those is repeating twice. Find those missing and
// repeating numbers respectively.
pair<int,int> missingAndRepeatingOptimal1(int n,vector<int>&arr)
{
    int totalSum = (n*(n+1))/2;
    int sum=accumulate(arr.begin(),arr.end(),0);
    int totalSquareSum = (n*(n+1)*(2*n + 1))/6;
    int squareSum = 0;
    for(int i=0;i<n;i++)
    {
        squareSum+=(arr[i]*arr[i]);
    }
    int xMinusy = sum-totalSum;
    int xSquareMinusySquare = squareSum-totalSquareSum;
    int xPlusy = xSquareMinusySquare/xMinusy;
    int x = (xMinusy+xPlusy)/2;
    int y = x-xMinusy;
    return {x,y};
}
pair<int,int> missingAndRepeatingOptimal2(int n,vector<int>&arr)
{
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr ^= arr[i];
        xr ^= (i+1);
    }
    int bitno=0;
    while(1)
    {
        if((xr & (1<<bitno)))
        {
            break;
        }
        bitno++;
    }
    int zero=0,one=0;
    for(int i=0;i<n;i++)
    {
        if((arr[i] & (1<<bitno)))
        {
            one ^= arr[i];
        }
        else
        {
            zero ^= arr[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if((i & (1<<bitno)))
        {
            one ^= i;
        }
        else
        {
            zero ^= i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == zero) cnt++;
    }
    if(cnt == 2) return {zero, one};
    return {one, zero};
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    pair<int,int> p = missingAndRepeatingOptimal1(n,arr);
    cout<<"The missing number is: "<<p.first<<endl;
    cout<<"The repeating number is: "<<p.second<<endl;
    p = missingAndRepeatingOptimal2(n, arr);
    cout<<"The missing number is: "<<p.first<<endl;
    cout<<"The repeating number is: "<<p.second<<endl;
}

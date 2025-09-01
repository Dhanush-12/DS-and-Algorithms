#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
// Time Complexity: O(n);
// Sapce Complexity: O(1);
void nextGreaterPermuationOptmial(int n,vector<int>&arr)
{
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {
        reverse(arr.begin(),arr.end());
    }
    for(int i=n-1;i>ind;i--)
    {
        if(arr[i]>arr[ind])
        {
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>orgarr=arr;
    cout<<"Using STL: "<<endl;
    do{
        for(auto a:arr)
        {
            cout<<a<<' ';
        }
        cout<<endl;
    } while(next_permutation(arr.begin(),arr.end()));
    nextGreaterPermuationOptmial(n,orgarr);
    cout<<"Using Optimal Approach: "<<endl;
    for(int i=0;i<n;i++) cout<<orgarr[i]<<' ';
    cout<<endl;
}
/*
4
2 1 3 4
*/

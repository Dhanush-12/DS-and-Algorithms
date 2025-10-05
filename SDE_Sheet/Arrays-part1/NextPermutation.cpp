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
// Another accepted method for calculating next greater permutation problem.
void nextGreaterPermutationOptimal1(int n, vector<int>&arr)
{
    stack<pair<int,int>>s;
    s.push({arr[n-1],n-1});
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=s.top().first)
        {
            s.push({arr[i],i});
        }
        else
        {
            int rightele=s.top().first;
            int ind=s.top().second;
            while(!s.empty() && s.top().first>arr[i])
            {
                rightele=s.top().first;
                ind=s.top().second;
                s.pop();
            }
            swap(arr[i],arr[ind]);
            sort(arr.begin()+i+1,arr.end());
            return;
        }
    }
    sort(arr.begin(),arr.end());
    return;
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

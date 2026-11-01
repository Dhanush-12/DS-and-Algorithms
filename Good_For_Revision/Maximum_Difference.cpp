#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given an integer array arr of integers, the task is to find the maximum absolute
    difference between the nearest left smaller element and the nearest right smaller element of
    every element in array arr. If for any component of the arr, the nearest smaller element
    doesn't exist then consider it as 0.

    Examples :

    Input: arr = [2, 1, 8]
    Output: 1
    Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1

    Input: arr = [2, 4, 8, 7, 7, 9, 3]
    Output: 4
    Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
*/
class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        int n = (int)arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> s;
        s.push(arr[0]);
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && s.top() >= arr[i]) s.pop();
            if(s.empty()) left[i] = 0;
            else left[i] = s.top();
            s.push(arr[i]);
        }
        while(!s.empty()) s.pop();
        s.push(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && s.top() >= arr[i]) s.pop();
            if(s.empty()) right[i] = 0;
            else right[i] = s.top();
            s.push(arr[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans, abs(left[i]-right[i]));
        }
        return ans;
    }
};
int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.findMaxDiff(arr)<<endl;
}
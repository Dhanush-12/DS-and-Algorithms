#include<bits/stdc++.h>
using namespace std;

/*
Problem: Given an array arr[], find the smallest number x such that when x is processed sequentially with each element of the array
(from index 0 to n-1), it never becomes negative, under the following conditions:

If x is greater than the current array element, x is increased by the difference between x and the array element.
If x is less than or equal to the current array element, x is decreased by the difference between the array element and x.
Examples:

Input: arr[] = [3, 4, 3, 2, 4]
Output: 4
*/

class Solution {
public:
    int find(vector<int>& arr) {
        long long need = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            need = (need + arr[i] + 1) / 2;
        }
        return max(1LL, need);
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.find(arr)<<endl;
}
/*
6
42 68 35 1 70 25
*/

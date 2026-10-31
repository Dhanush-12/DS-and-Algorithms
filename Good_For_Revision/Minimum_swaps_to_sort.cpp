#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given an array arr[] of distinct elements. Find the minimum number of swaps
    required to sort the array in strictly increasing order.

    Examples:
    Input: arr[] = [2, 8, 5, 4]
    Output: 1
    Explanation: Swap 8 with 4 to get the sorted array.

    Input: arr[] = [10, 19, 6, 3, 5]
    Output: 2
    Explanation: Swap 10 with 3 and 19 with 5 to get the sorted array.

    Input: arr[] = [1, 3, 4, 5, 6]
    Output: 0
    Explanation: Input array is already sorted.
*/
int ans;
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = (int)arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]] = i;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(temp[i] == arr[i]) continue;
            ans++;
            int where = mp[temp[i]];
            arr[where] = arr[i];
            mp[arr[i]] = where;
            arr[i] = temp[i];
            mp[arr[i]] = i;
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
    cout<<s.minSwaps(arr)<<endl;
}
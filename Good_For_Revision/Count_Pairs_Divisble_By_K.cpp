#include<bits/stdc++.h>
using namespace std;

/*

    Problem : Given an array arr[] and positive integer k, count total number of pairs in the array whose sum is divisible by k.

    Examples:

    Input :  arr[] = [2, 2, 1, 7, 5, 3], k = 4
    Output : 5
    Explanation : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3).

*/

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        int n = (int)arr.size();
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i]%k;
        }
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
            {
                ans += mp[0];
                mp[0]++;
                continue;
            }
            int rem = k - arr[i];
            ans += mp[rem];
            mp[arr[i]]++;
        }
        return ans;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.countKdivPairs(arr, k)<<endl;
}

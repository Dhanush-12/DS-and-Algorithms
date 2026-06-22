#include <bits/stdc++.h>
using namespace std;

/* Given an array of non-negative numbers, divide the array into two parts such that the average of both the parts is equal.
   Return both the parts if exists, otherwise, print -1;

   Solution: Lets say totalSum = S and totalElements = N, number of elements in array1 is n1 with sum s1 and number of elements in the array2 is n2
   and with sum s2, then from the problem, we can form an equation: s1/n1 = s2/n2, substituting s2 = S-s1 and n2 = N-n1, we get an equaltion
   -> s1 = (S*n1)/N, as we know that S and N are constant for an array, we need to check for satisfaction of n1 from 1 to n-1.
*/

class Solution {
    // Time Complexity: O(2^n)
    // Space Complexity: O(2*n)
    bool check(int ind, int s1, int i, vector<int>&arr, vector<int>&res)
    {
        if(i == 0) return (s1 == 0);
        if(ind >= arr.size()) return false;

        if(arr[ind] <= s1)
        {
            res.push_back(ind);
            if(check(ind+1, s1-arr[ind], i-1, arr, res))
            {
                return true;
            }
            res.pop_back();
        }

        if(check(ind+1, s1, i, arr, res)) return true;
        return false;
    }
    // Take and not_take format recursion.
    bool check1(int ind, int s1, int i, vector<int>&res, vector<int>&arr)
    {
        if(i == 0) return (s1 == 0);
        if(ind >= arr.size()) return false;

        bool take = false;

        if(arr[ind] <= s1)
        {
            res.push_back(ind);
            take = check(ind+1, s1-arr[ind], i-1, res, arr);
            if(!take) res.pop_back();
        }
        bool not_take = ((!take) ? check(ind+1, s1, i, res, arr) : false);

        return (take | not_take);
    }
    // Memorization Solution
    // Time Complexity: O(n*sum*ele)
    // Space Complexity: O(n*sum*ele)
    bool check_memo(int ind, int sum, int ele, vector<int>&arr, vector<int>&res, vector<vector<vector<bool>>>&dp)
    {
        if(ele == 0) return (sum == 0);
        if(ind >= arr.size()) return false;

        if(dp[ind][sum][ele] == false) return false;

        if(arr[ind] <= sum)
        {
            res.push_back(ind);
            if(check_memo(ind+1, sum-arr[ind], ele-1, arr, res, dp))
            {
                return dp[ind][sum][ele] = true;
            }
            res.pop_back();
        }

        if(check_memo(ind+1, sum, ele, arr, res, dp)) return dp[ind][sum][ele] = true;

        return dp[ind][sum][ele] = false;
    }
public:
    void equalAveragePartition(int n, vector<int>&arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(sum+1, vector<bool>(n, true)));
        for(int i=1;i<n;i++)
        {
            if((sum * i) % n == 0)
            {
                int s1 = (sum*i)/n;
                vector<int>res;
                vector<int> remaining;
                /*if(check(0, s1, i, arr, res))
                {
                    int ind = 0;
                    for(int i = 0; i < arr.size(); i++)
                    {
                        if(ind < res.size() && res[ind] == i)
                        {
                            cout<<arr[res[ind]]<<" ";
                            ind++;
                        }
                        else
                        {
                            remaining.push_back(arr[i]);
                        }
                    }
                    cout<<endl;
                    for(int i=0;i<remaining.size();i++)
                    {
                        cout<<remaining[i]<<" ";
                    }
                    cout<<endl;
                    return;
                }*/
                if(check_memo(0, s1, i, arr, res, dp))
                {
                    int ind = 0;
                    for(int i = 0; i < arr.size(); i++)
                    {
                        if(ind < res.size() && res[ind] == i)
                        {
                            cout<<arr[res[ind]]<<" ";
                            ind++;
                        }
                        else
                        {
                            remaining.push_back(arr[i]);
                        }
                    }
                    cout<<endl;
                    for(int i=0;i<remaining.size();i++)
                    {
                        cout<<remaining[i]<<" ";
                    }
                    cout<<endl;
                    return;
                }
            }
        }
        cout<<-1<<endl;
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    s.equalAveragePartition(n, arr);
}

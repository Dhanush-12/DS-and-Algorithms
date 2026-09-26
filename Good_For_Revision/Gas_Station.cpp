#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: There are n gas stations along a circular tour. You are given two integer arrays
    gas[] and cost[], where gas[i] is the amount of gas available at station i and cost[i] is the
    gas needed to travel from station i to station (i+1). You have a car with an unlimited gas
    tank and start with an empty tank at some station. Your task is to return the index of the
    starting station if it is possible to travel once around the circular route in a clockwise
    direction without running out of gas at any station; otherwise, return -1.

    Note: If a solution exists, it is guaranteed to be unique.

    Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
    Output: 2

    Input: gas[] = [3, 9], cost[] = [7, 6]
    Output: -1
*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = (int)gas.size();
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int i=0;i<n;i++)
        {
            int diff = gas[i] - cost[i];
            
            total += diff;
            curr += diff;
            
            if(curr < 0)
            {
                start = i+1;
                curr = 0;
            }
        }
        
        if(total < 0) return -1;
        return start;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> gas(n), cost(n);
    for(int i=0;i<n;i++) cin>>gas[i];
    for(int i=0;i<n;i++) cin>>cost[i];
    Solution s;
    cout<<s.startStation(gas, cost)<<endl;
}
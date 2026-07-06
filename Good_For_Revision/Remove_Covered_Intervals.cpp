#include<bits/stdc++.h>
using namespace std;

/*

    Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered
    by another interval in the list.The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

    Return the number of remaining intervals.

    Example 1:

    Input: intervals = [[1,4],[3,6],[2,8]]
    Output: 2
    Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

*/
class Solution {
public:
    // Time Complexity : O(n * log(n))
    // Space Complexity: O(1)
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>a, vector<int>b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int maxEnd = 0;
        int count = 0;
        for(auto& interval : intervals) {
            int end = interval[1];
            if(end > maxEnd) {
                count++;
                maxEnd = end;
            }
        }
        return count;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1];
    Solution s;
    cout<<s.removeCoveredIntervals(arr)<<endl;
}

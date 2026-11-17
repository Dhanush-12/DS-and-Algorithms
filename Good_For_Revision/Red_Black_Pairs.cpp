#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: There is a table of 2×n cells. Each cell of the table is colored either red or black.
    You want to repaint some cells of this table so that there exists at least one way to partition
    all cells into n pairs such that the following conditions hold: 
    -> the cells in each pair have the same color; 
    -> the cells in each pair share a side.

    What is the minimum number of cells that need to be repainted?

    Input:
    Each test contains multiple test cases. The first line contains the number of test cases t 
    (1≤t≤10^4). The description of the test cases follows.

    The first line of each test case contains one integer n (1≤n≤2⋅10^5).

    The second and third lines of each test case describe the colors of the cells. Each line contains
    a string consisting of exactly n letters "R" and/or "B".

    Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅105

    Output:
    For each test case, output one integer — the minimum number of cells that need to be repainted.

    Example
    Input:

    5
    1
    R
    B
    2
    BR
    BR
    3
    RBR
    BRB
    4
    RRBB
    BBRB
    5
    RBRBR
    BBBRB
    Output:

    1
    0
    3
    1
    4
*/
void solve()
{
    int n;
    cin>>n;
    vector<string> arr(2);
    cin>>arr[0]>>arr[1];
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=0;i<n;i++)
    {
        dp[i+1] = min(dp[i+1], dp[i]+(arr[0][i] != arr[1][i]));
        if(i+1 < n)
        {
            dp[i+2] = min(dp[i+2], dp[i]+(arr[0][i] != arr[0][i+1])+(arr[1][i] != arr[1][i+1]));
        }
    }
    cout<<dp[n]<<endl;
}
int main() 
{
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
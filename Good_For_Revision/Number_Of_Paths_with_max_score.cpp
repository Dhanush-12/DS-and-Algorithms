#include<bits/stdc++.h>
using namespace std;

/*

    Problem: You are given a square board of characters. You can move on the board starting at the bottom right square marked with
    the character 'S'. You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled
    either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) '
    only if there is no obstacle there.

    Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is
    the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

    In case there is no path, return [0, 0].



    Example 1:

    Input: board = ["E23","2X2","12S"]
    Output: [7,1]
    Example 2:

    Input: board = ["E12","1X1","21S"]
    Output: [4,2]
    Example 3:

    Input: board = ["E11","XXX","11S"]
    Output: [0,0]

*/
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = (int)board.size();
        const int MOD = 1e9+7;
        const int NEG = -1e9;

        vector<vector<int>> score(n, vector<int>(n, NEG));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(board[i][j] == 'X') continue;
                if(i == n-1 && j == n-1) continue;

                vector<pair<int,int>> next = {
                    {i+1, j},
                    {i, j+1},
                    {i+1, j+1}
                };
                int best = NEG;
                int count = 0;

                for (const auto &p : next) {
                    int x = p.first;
                    int y = p.second;
                    if(x >= n || y>=n) continue;
                    if(score[x][y] == NEG) continue;

                    if(score[x][y] > best) {
                        best = score[x][y];
                        count = ways[x][y];
                    } else if(score[x][y] == best) {
                        count = (count+ways[x][y]) % MOD;
                    }
                }

                if(best == NEG) continue;

                int val = 0;
                if(board[i][j] >= '1' && board[i][j] <= '9') {
                    val = board[i][j]-'0';
                }

                score[i][j] = best+val;
                ways[i][j] = count;
            }
        }
        if(ways[0][0] == 0) return {0,0};
        return {score[0][0], ways[0][0]};
    }
};
int main()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    vector<int> ans = s.pathsWithMaxScore(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}

#include <bits/stdc++.h>
using namespace std;
// Time Complexity : O(N*(2^N));
vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> result;
    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                ans.push_back(v[j]);
            }
        }
        result.push_back(ans);
        ans.clear();
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans = pwset(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
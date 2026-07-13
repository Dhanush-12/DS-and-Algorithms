#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;

/*
    Problem : An integer has sequential digits if and only if each digit in the number is one more
    than the previous digit. Return a sorted list of all the integers in the range [low, high] inclusive
    that have sequential digits.

    Example 1:

    Input: low = 100, high = 300
    Output: [123,234]
*/

vector<int> preComputed;
const int maxi = 1000000000;
int init = []() {
    int init = 1;
    int _init = init;
    int st = 2;
    int to_add = 1;
    while(init <= maxi)
    {
        preComputed.push_back(init);
        if(init % 10 == 9)
        {
            init = (_init*10) + st;
            st++;
            to_add = (to_add*10) + 1;
            _init = init;
            continue;
        }
        init += to_add;
    }
    return 0;
}();
class Solution {
public:
    // Aprroach with precomputation with Time Complexity less than: O(high-low)
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int l_ind = lower_bound(preComputed.begin(), preComputed.end(), low) - preComputed.begin();
        int h_ind = upper_bound(preComputed.begin(), preComputed.end(), high) - preComputed.begin();

        for(int i=l_ind;i<h_ind;i++) ans.push_back(preComputed[i]);
        return ans;
    }
    // Another Approach without precomputation
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            int num=i;
            int next=i+1;
            while(num<=high  && next<=9)
            {
                num=num*10 + next;
                if(low<=num && num<=high) ans.push_back(num);
                next++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    int low, high;
    cin>>low>>high;
    Solution s;
    vector<int> ans = s.sequentialDigits(low, high);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

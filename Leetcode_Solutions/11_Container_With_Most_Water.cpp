#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = (int)height.size();
        int i=0, j=n-1;
        while(i<j)
        {
            ans = max(ans, (j-i)*min(height[i], height[j]));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.maxArea(arr)<<endl;
}

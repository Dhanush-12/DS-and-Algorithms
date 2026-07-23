#include<bits/stdc++.h>
using namespace std;
const int inf = 1e5;
class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int lowerBound = INT_MIN;
        for(int val : arr)
        {
            if(val < lowerBound) {
                return false;
            }

            while(!st.empty() && val > st.top())
            {
                lowerBound = st.top();
                st.pop();
            }
            st.push(val);
        }
        return true;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.canRepresentBST(arr)<<endl;
}

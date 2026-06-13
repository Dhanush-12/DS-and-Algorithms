#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int n=n1+n2;
        int left=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1)
            {
                if(n%2) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
    // Overloaded method
    // Easy approach: Do Binary search on the number of smallest array elements to include in left half of the final array
    // Time Complexity : O(log(min(n, m)))
    double findMedianSortedArrays(int n, int m, vector<int>& a, vector<int>& b) {
        if (n > m) return findMedianSortedArrays(m, n, b, a);

        int totalLeft = (n + m + 1) / 2;

        int low = 0, high = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            int fromB = totalLeft - mid;

            int lefta = (mid > 0) ? a[mid - 1] : INT_MIN;
            int righta = (mid < n) ? a[mid] : INT_MAX;

            int leftb = (fromB > 0) ? b[fromB - 1] : INT_MIN;
            int rightb = (fromB < m) ? b[fromB] : INT_MAX;

            if (lefta <= rightb && leftb <= righta) {
                if ((n + m) % 2 == 1) {
                    return max(lefta, leftb);
                } else {
                    return (max(lefta, leftb) + min(righta, rightb)) / 2.0;
                }
            }
            else if (lefta > rightb) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return 0.0;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    Solution s;
    cout<<fixed<<setprecision(5)<<s.findMedianSortedArrays(a, b)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
    void mergeSort(int s, int e, vector<pair<int,int>>& arr, vector<int>&ind, vector<pair<int,int>>&temp)
    {
        if(s >= e) return;
        int mid = s+(e-s)/2;
         mergeSort(s, mid, arr, ind, temp);
         mergeSort(mid+1, e, arr, ind, temp);

         int left=s, right=mid+1;
         int idx=s;
         int nRightLessThanLeft=0;
         while(left<=mid and right<=e)
         {
            if(arr[left] < arr[right])
            {
                ind[arr[left].second]+=nRightLessThanLeft;
                temp[idx++]=arr[left++];
            }
            else if(arr[left] > arr[right])
            {
                temp[idx++] = arr[right++];
                nRightLessThanLeft++;
            }
            else
            {
                left++;
                right++;
            }
         }
         while(left<=mid)
         {
            ind[arr[left].second]+=nRightLessThanLeft;
            temp[idx++]=arr[left++];
         }
         while(right<=e)
         {
            temp[idx++]=arr[right++];
         }
         for(int i=s;i<=e;i++)
         {
            arr[i]=temp[i];
         }
    }
        int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //Modification 1: cnt variable to count the pairs:
        int cnt = 0;

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); //Modification 2
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt; // Modification 3
    }
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
public:
    // This function returns the number of elements that are smaller than the current element to its right
    vector<int> countSmaller(vector<int>& nums) {
        int n=(int)nums.size();
        vector<pair<int,int>>nn;
        vector<int>ind(n,0);
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        {
            nn.push_back({nums[i],i});
            temp.push_back({nums[i],i});
        }
        mergeSort(0, n-1, nn, ind, temp);
        return ind;
    }
    // This function return the total sum of number of pairs of countInversions
    int countInversions(int n, vector<int>&arr)
    {
        return mergeSort(arr, 0, n-1);
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    vector<int> ans = s.countSmaller(arr);
    cout<<"The number of elements that are smaller than the each element on its right are: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Total number of count Inversions are: "<<s.countInversions(n,arr)<<endl;
}


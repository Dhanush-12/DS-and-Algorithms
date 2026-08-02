#include<bits/stdc++.h>
using namespace std;
/*
    Problem : You are given an array A of length N. You take an array B of length N such that B[i] = 0 for each 1 <= i <= N.
    You can apply the following operation on B any number of times:

    Choose (N - 1) distinct indices and add 1 to each of those indices.
    Task

    Find the number of operations required to convert array B into array A by applying the given operation. Print -1 if it is
    impossible to do so.

    Examples:
    Input:

    2 - Testcases
    3
    3 1 0
    2
    0 2
    Output:
    -1
    2

    Solution:
    Step 1: Understand one operation, Suppose N = 5. One operation chooses N-1 = 4 indices. So exactly one index is skipped.

    For example

    Before

    0 0 0 0 0

    Skip index 3

    ↓

    1 1 0 1 1

    Every operation increases all elements except one.

    Step 2: Think in terms of skipped times, Suppose we perform k operations. Every element could have been skipped some number of
    times.

    Let, skip[i] = number of operations where i was NOT chosen. Since one index is skipped every operation, ∑skip[i]=k. Now,
    how much does element i increase? It is increased in every operation except those in which it was skipped. Therefore

    A[i]=k−skip[i]

    This equation is the entire problem.

    Step 3: Rearrange

    From A[i]=k−skip[i], we get, skip[i]=k−A[i], Since skip[i] counts operations, it must satisfy skip[i] >= 0

    Therefore, k ≥ A[i] for every i. Hence k≥max(A), So yes, the smallest possible answer is at least the maximum element.

    Step 4: Use the sum

    We also know, ∑skip[i]=k, Substitute, ∑(k−A[i])=k -> Nk−∑A=k -> (N−1)k=∑A. Therefore k = ∑A / N−1
        ​
    Now this is amazing because k is uniquely determined.

    Step 5: Conditions

    A solution exists iff

    Condition 1: k must be an integer. So, sum % (N-1) == 0
    Condition 2: Since skip[i]=k-A[i] must be non-negative, A[i] <= k for every i. Equivalently, max(A)<=k

*/
int solve (int N, vector<int> A) {
   long long sum = accumulate(A.begin(), A.end(), 0ll);
   if(sum % (N-1))
   {
       return -1;
   }
   long long k = sum/(N-1);
   if(*max_element(A.begin(), A.end()) > k) return -1;
   return k;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(n, arr)<<endl;
}

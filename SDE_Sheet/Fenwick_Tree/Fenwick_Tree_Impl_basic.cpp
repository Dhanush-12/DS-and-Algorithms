#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;
class Fenwick {
    vector<int> bit;
    int n;
    public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    void add(int ind, int val) {
        while(ind <= n) {
            bit[ind] += val;
            ind += ind & -ind;
        }
    }
    int sum(int ind)
    {
        int ans = 0;
        while(ind > 0) {
            ans += bit[ind];
            ind -= ind & -ind;
        }
        return ans;
    }
    int findSum(int k)
    {
        int curr = 0, ans = 0, prevSum = 0;
        for(int i=log2(n);i>=0;i--)
        {
            if(bit[curr + (1<<i)] + prevSum < k) {
                curr = curr + (1 << i);
                prevSum += bit[curr];
            }
        }
        return curr+1;
    }
    void print() {
        for(int i=0;i<bit.size();i++) cout<<bit[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Fenwick fw(n);
    for(int i=0;i<n;i++)
    {
        fw.add(i+1, arr[i]); // Fenwick tree is 1 based index, so we have to pass 1 based index.
        //fw.print();
    }
    cout<<fw.sum(14)<<endl;
    cout<<fw.findSum(1)<<endl;
}
/*
16
1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
*/

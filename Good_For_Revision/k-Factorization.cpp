#include<bits/stdc++.h>
#define ll long long
#define sp(x, y) fixed << setprecision(x) << y
using namespace std;

/*
    Problem: Given a positive integer n, find k integers (not necessary distinct) such that all 
    these integers are strictly greater than 1, and their product is equal to n.

    Input:
    The first line contains two integers n and k (2 ≤ n ≤ 100000, 1 ≤ k ≤ 20).

    Output:
    If it's impossible to find the representation of n as a product of k numbers, print -1.

    Otherwise, print k integers in any order. Their product must be equal to n. If there are
    multiple answers, print any of them.

    Example:
    Input: 100000 2
    Output: 2 50000

    Input: 100000 20
    Output: -1

    Input: 1024 5
    Output: 2 64 2 2 2
*/

vector<int> primes;
const int inf = 1000001;
int init = []() {
    if (inf < 2) return 0;
    vector<bool> is_prime(inf + 1, true);
    is_prime[0] = is_prime[1] = false;
    primes.push_back(2);

    for (int i = 3; i * i <= inf; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= inf; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 3; i <= inf; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return 0;
}();
void print(vector<int>arr)
{
    int n=(int)(arr.size());
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void accepted()
{
    int n,k;
    cin>>n>>k;
    if(k == 1)
    {
        cout<<n<<endl;
        return;
    }
    vector<int> ans;
    for(int i=0;i<primes.size();i++)
    {
        int currPrime = primes[i];
        if(currPrime > n)
        {
            if(n > 1) ans.push_back(n);
            break;
        }
        while(n % currPrime == 0)
        {
            ans.push_back(currPrime);
            n /= currPrime;
            if(n > 1 && (ans.size()+1) == k)
            {
                ans.push_back(n);
                print(ans);
                return;
            }
        }
    }
    if(ans.size() < k)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        accepted();
    }
    return 0;
}
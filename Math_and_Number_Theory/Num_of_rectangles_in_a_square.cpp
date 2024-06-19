#include<bits/stdc++.h>
#define MOD 1000000007;
using namespace std;
// number of rectangles in a N*N square matrix excluding the squares.
int countRectangles(int n) {
    int count = (n * (n + 1) / 2) * (n * (n + 1) / 2) - n * (n + 1) * (2 * n + 1) / 6;
    return count;
}
//to handles the large test cases
int countRectangles1(int n) {
    long long count = ((long long)(n) * (n + 1) / 2) % MOD;
    count = (count * count - (long long)(n) * (n + 1) * (2 * n + 1) / 6) % MOD;
    if (count < 0)
        count += MOD;
    return (int)(count);
}

int main()
{
    int n;
    cin>>n;
    cout<<countRectangles1(n)<<endl;
}


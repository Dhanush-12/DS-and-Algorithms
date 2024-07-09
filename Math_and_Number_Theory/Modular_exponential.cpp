#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
    // Function to compute (base^exp) % mod
long long modExp(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
}
int main() {
   long long ans=modExp(4,5);
   cout<<ans<<endl;
}


#include<bits/stdc++.h>
using namespace std;

/*
Problem: Cut rope to maximise product : Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their
lengths is maximized. At least one cut is mandatory.

Solution:
This is the classic Integer Break problem.

You must cut rope at least once, and maximize product of all pieces.

Best rule:

Prefer cutting pieces of length 3
But if remainder becomes 1, replace 3 + 1 with 2 + 2
If remainder is 2, keep it as 2

Examples:

n = 5
5 = 3 + 2
product = 3 * 2 = 6
n = 10
10 = 3 + 3 + 4
product = 3 * 3 * 4 = 36

Why not 3 + 3 + 3 + 1?

3 * 3 * 3 * 1 = 27

But:

3 * 3 * 2 * 2 = 36

So avoid remainder 1.

Base cases

Because at least one cut is mandatory:

n = 2 → 1 * 1 = 1
n = 3 → 1 * 2 = 2

Logic of while (n > 4)

Keep taking 3 until remaining rope is 2, 3, or 4.

Because:

4 is better as 2 * 2, but product is same as 4

So we can simply multiply the remaining n at the end.

why only 3 gives maximum why not other number?
Answer:
This is one of those beautiful math proofs that appears in interviews and competitive programming.

The key idea is:

Any piece ≥ 5 should be broken further

Suppose you have a piece of length x ≥ 5.

Break it into:

3 + (x - 3)

Compare:

Original product = x
New product      = 3 × (x - 3)

Let's see when the new product is better:

3(x - 3) > x
3x - 9 > x
2x > 9
x > 4.5

So for every:

x ≥ 5

breaking off a 3 increases the product.

Examples:

5  -> 3 × 2 = 6   > 5
6  -> 3 × 3 = 9   > 6
7  -> 3 × 4 = 12  > 7
8  -> 3 × 5 = 15  > 8

Therefore, an optimal solution can never contain a piece ≥ 5.

Now let's compare small pieces.

Why not use 1?
3 × 1 = 3
2 × 2 = 4

So whenever you see:

3 + 1

replace it with:

2 + 2

and get a larger product.

Hence, an optimal solution never contains 1.

Why prefer 3 over 2?

Compare equal lengths:

For length 6:

3 + 3 → 3 × 3 = 9
2 + 2 + 2 → 2 × 2 × 2 = 8

For length 9:

3 + 3 + 3 → 27
2 + 2 + 2 + 3 → 24

3s consistently give a larger product.

The deeper mathematical reason

If you allow real numbers, the product is maximized when the pieces are close to:

e ≈ 2.718

Since rope lengths must be integers, the closest useful integer is:

3

That's why the optimal strategy is:

Take as many 3s as possible.
If remainder is 1, convert one 3 + 1 into 2 + 2.
If remainder is 2, keep it.

Example:

n = 10

3 + 3 + 3 + 1   → 27
3 + 3 + 2 + 2   → 36  ✓

That's the mathematical reason behind the famous "keep cutting 3s" rule.
*/

class Solution {
  public:
    int maxProduct(int n) {
        if(n <= 3) return n-1;

        int ans = 1;
        while(n > 4)
        {
            ans *= 3;
            n -= 3;
        }

        return ans*n;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.maxProduct(n)<<endl;
}

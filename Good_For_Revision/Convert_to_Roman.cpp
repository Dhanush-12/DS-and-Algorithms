#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Given a positive integer n, convert it into its equivalent Roman numeral representation.

    Roman numerals are formed using the following symbols:
    
    Value   Symbol
    1000        M
    900         CM
    500         D
    400         CD
    100         C
    90          XC
    50          L   
    40          XL
    10          X
    9           IX
    5           V
    4           IV
    1           I

    Input: n = 9
    Output: IX
    Explanation: 9 is represented as IX (10 - 1).

    Input: n = 493
    Output: CDXCIII
    Explanation: 493 = 400 + 90 + 3, which is represented as CD + XC + III = CDXCIII.
*/
class Solution {
  public:
    string convertToRoman(int n) {
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string ans = "";

        for(int i=0;i<values.size();i++)
        {
            while(n >= values[i])
            {
                ans += symbols[i];
                n -= values[i];
            }
        }

        return ans;
    }
};
int main() 
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.convertToRoman(n)<<endl;
}
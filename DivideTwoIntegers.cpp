#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend >= 0) == (divisor >= 0);
        int a = abs(dividend);
        int b = abs(divisor);

        int result = 0;
        while (a - b >= 0)
        {
            int count = 0;
            while (a - (b << 1 << count) >= 0)
                count++;

            result += 1 << count;
            a -= b << count;
        }

        return sign ? result : -result;
    }
};
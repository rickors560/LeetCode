#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getBitLength(int n)
    {
        return log2(n) + 1;
    }

public:
    int concatenatedBinary(int n)
    {
        int mod = 1e9 + 7;
        long result = 0;

        for (int i = 1; i <= n; i++)
        {
            int l = getBitLength(i);
            result = (((result << l) % mod) + i) % mod;
        }

        return result;
    }
};
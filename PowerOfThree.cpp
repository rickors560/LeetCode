#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        double result = log10(n) / log10(3);
        return trunc(result) - result == 0;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        double result = log(n) / log(4); // Take log base 4 for n.
        return trunc(result) - result == 0;
    }
};
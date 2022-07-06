#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        n -= 2;

        int result = 0;

        int x = 0;
        int y = 1;

        while (n >= 0)
        {
            result = x + y;
            x = y;
            y = result;
            n--;
        }

        return result;
    }
};
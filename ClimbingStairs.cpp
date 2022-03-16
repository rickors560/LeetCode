#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    map<int, int> cache;

public:
    // Using Fibonacci Series
    int climbStairs1(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int result = 0;

        int p = 2;
        int q = 1;

        for (int i = 2; i < n; i++)
        {
            result = p + q;
            q = p;
            p = result;
        }

        return result;
    }

    // Using DP
    int climbStairs2(int n)
    {
        if (cache.find(n) != cache.end())
            return cache[n];

        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int result = climbStairs2(n - 1) + climbStairs2(n - 2);
        cache.insert({n, result});
        return result;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int solve(int n, vector<int> &memo)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        if (memo[n] != 0)
            return memo[n];

        bool isEven = (n % 2 == 0);

        if (isEven)
        {
            memo[n] = solve(n / 2, memo);
            return memo[n];
        }
        else
        {
            memo[n] = 1 + solve(n / 2, memo);
            return memo[n];
        }
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1);

        for (int i = 0; i <= n; i++)
        {
            result[i] = solve(i, result);
        }

        return result;
    }
};
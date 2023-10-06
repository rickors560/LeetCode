#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Using Recursion [Top-Bottom]
    int solve(int n, vector<int> &memo)
    {
        if (n == 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        int result = 0;
        for (int i = 1; i < n; i++)
        {
            int a = i;
            int b = n - a;
            result = max({result, a * b, a * solve(b, memo)});
        }

        return memo[n] = result;
    }

    // Using Iterative [Bottom-Up]
    int solve(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                int a = j;
                int b = i - a;
                dp[i] = max({dp[i], a * b, a * dp[b]});
            }
        }

        return dp[n];
    }

public:
    int integerBreak(int n)
    {
        // vector<int> memo(n + 1, -1);
        // return solve(n, memo);

        return solve(n);
    }
};
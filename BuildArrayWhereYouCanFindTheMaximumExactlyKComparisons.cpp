#include <bits/stdc++.h>
using namespace std;

// Using Iteration
class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        static long long const mod = 1e9 + 7;
        long long dp[52][102][52];
        memset(dp, 0, sizeof(dp));

        for (int val = 0; val <= m; val++)
        {
            dp[n][val][k] = 1;
        }

        for (int len = n; len >= 0; len--)
        {
            for (int maxVal = m; maxVal >= 0; maxVal--)
            {
                for (int cost = k; cost >= 0; cost--)
                {
                    for (int val = 1; val <= m; val++)
                    {
                        if (val > maxVal)
                        {
                            dp[len][maxVal][cost] = (dp[len][maxVal][cost] + dp[len + 1][val][cost + 1]) % mod;
                        }
                        else
                        {
                            dp[len][maxVal][cost] = (dp[len][maxVal][cost] + dp[len + 1][maxVal][cost]) % mod;
                        }
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};

// Using Recursion
class Solution1
{
private:
    static long long const mod = 1e9 + 7;
    long long dp[55][105][55];
    long long solve(int len, int maxVal, int cost, int n, int m, int k)
    {
        if (n == len)
        {
            if (k == cost)
                return 1;
            else
                return 0;
        }

        if (dp[len][maxVal][cost] != -1)
            return dp[len][maxVal][cost];

        int ans = 0;

        for (int val = 1; val <= m; val++)
        {
            if (val > maxVal)
            {
                ans = (ans + solve(len + 1, val, cost + 1, n, m, k)) % mod;
            }
            else
            {
                ans = (ans + solve(len + 1, maxVal, cost, n, m, k)) % mod;
            }
        }

        return dp[len][maxVal][cost] = ans;
    }

public:
    int numOfArrays(int n, int m, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, m, k);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;
    int mod = 1e9 + 7;

    int dfs(int n, int &k, int target)
    {
        if (target == 0 && n == 0)
            return 1;

        if (n == 0 || target == 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int result = 0;
        for (int i = 1; i <= k; i++)
        {
            if (target - i >= 0)
                result = (result + dfs(n - 1, k, target - i)) % mod;
            else
                break;
        }

        return dp[n][target] = result;
    }

    int bottomUp(int n, int k, int target)
    {
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                for (int x = 1; x <= k; x++)
                {
                    if (j - x >= 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
                    else
                        break;
                }
            }
        }

        return dp[n][target];
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        // dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        // return dfs(n, k, target);
        return bottomUp(n, k, target);
    }
};

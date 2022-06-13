#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

    int dfs(vector<vector<int>> &triangle, int i, int j, int n)
    {
        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int bottom = dfs(triangle, i + 1, j, n);
        int bottomRight = dfs(triangle, i + 1, j + 1, n);

        return dp[i][j] = triangle[i][j] + min(bottom, bottomRight);
    }

    int bottomUp(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            dp[n - 1][i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int bottom = dp[i + 1][j] + triangle[i][j];
                int bottomRight = dp[i + 1][j + 1] + triangle[i][j];

                dp[i][j] = min(bottom, bottomRight);
            }
        }

        return dp[0][0];
    }

public:
    int
    minimumTotal(vector<vector<int>> &triangle)
    {
        // int n = triangle.size();
        // dp = vector<vector<int>>(n, vector<int>(n, -1));
        // return dfs(triangle, 0, 0, n);
        return bottomUp(triangle);
    }
};
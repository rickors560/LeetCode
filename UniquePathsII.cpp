#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;
    int dp[100][100];

    // Top-Down (Memoization)
    int topDown(vector<vector<int>> &obstacleGrid, int i, int j)
    {
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || obstacleGrid[i][j])
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        if (dp[i][j])
            return dp[i][j];

        return dp[i][j] = topDown(obstacleGrid, i + 1, j) + topDown(obstacleGrid, i, j + 1);
    }

    // Bottom-Up (Tabulation)   [ Faster than Top-Down as it doesn't use memory stack for recursion ]
    int bottomUp(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1])
            return 0;

        // Initialize dp table for 1st column for each unblocked cell there is path(1)
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[i][0]) // If current cell is blocked then we can't move further down
            {
                dp[i][0] = 0;
                break;
            }
            else
                dp[i][0] = 1;
        }

        // Initialize dp table for 1st row for each unblocked cell there is path(1)
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[0][j]) // If current cell is blocked then we can't move further right
            {
                dp[0][j] = 0;
                break;
            }
            else
                dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (obstacleGrid[i][j])
                    dp[i][j] = 0; // Path will be 0
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // no. of paths for current cell is sum(no. of paths to left and top cell)
            }
        }

        return dp[n - 1][m - 1];
    }

public:
    int
    uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        //  return dfs(obstacleGrid, 0, 0);
        return bottomUp(obstacleGrid);
    }
};
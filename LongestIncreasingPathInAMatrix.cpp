#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

    int dfs(vector<vector<int>> &matrix, int i, int j, int prevElement)
    {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= prevElement)
            return 0;

        if (dp[i][j])
            return dp[i][j];

        int left = dfs(matrix, i - 1, j, matrix[i][j]);
        int right = dfs(matrix, i + 1, j, matrix[i][j]);
        int top = dfs(matrix, i, j - 1, matrix[i][j]);
        int bottom = dfs(matrix, i, j + 1, matrix[i][j]);

        return dp[i][j] = 1 + max({left, right, top, bottom});
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n, vector<int>(m));

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result = max(result, dfs(matrix, i, j, -1));
            }
        }

        return result;
    }
};
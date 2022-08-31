#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int m, int n, int i, int j, vector<vector<bool>> &visited, int prevHeight, vector<vector<int>> &heights)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || prevHeight > heights[i][j])
            return;

        visited[i][j] = true;
        dfs(m, n, i + 1, j, visited, heights[i][j], heights);
        dfs(m, n, i - 1, j, visited, heights[i][j], heights);
        dfs(m, n, i, j + 1, visited, heights[i][j], heights);
        dfs(m, n, i, j - 1, visited, heights[i][j], heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
            dfs(m, n, i, 0, pacific, heights[i][0], heights); // Left Border for Pacific
        for (int i = 0; i < n; i++)
            dfs(m, n, 0, i, pacific, heights[0][i], heights); // Top Border for Pacific

        for (int i = 0; i < m; i++)
            dfs(m, n, i, n - 1, atlantic, heights[i][n - 1], heights); // Right Border for Atlantic
        for (int i = 0; i < n; i++)
            dfs(m, n, m - 1, i, atlantic, heights[m - 1][i], heights); // Bottom Border for Atlantic

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
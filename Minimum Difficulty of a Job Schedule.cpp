#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

    int dfs(vector<int> &jobDifficulty, int d, int index)
    {
        if (d == 1)
        {
            int result = 0;
            for (int i = index; i < jobDifficulty.size(); i++)
                result = max(result, jobDifficulty[i]);
            return result;
        }

        if (dp[d][index] != -1)
            return dp[d][index];

        int result = INT_MAX;

        int leftMax = 0;
        for (int i = index; i < jobDifficulty.size() - d + 1; i++)
        {
            leftMax = max(leftMax, jobDifficulty[i]);
            int rightMax = dfs(jobDifficulty, d - 1, i + 1);
            result = min(result, leftMax + rightMax);
        }

        return dp[d][index] = result;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        if (jobDifficulty.size() < d)
            return -1;

        dp = vector<vector<int>>(d + 1, vector<int>(jobDifficulty.size() + 1, -1));
        return dfs(jobDifficulty, d, 0);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

    // With top-down + memoization + recursion (with longest common subsequence)
    int longestCommonSubsequence(string &word1, string &word2, int i, int j)
    {
        if (i == word1.size() || j == word2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = 1 + longestCommonSubsequence(word1, word2, i + 1, j + 1);

        else
            return dp[i][j] = max(longestCommonSubsequence(word1, word2, i + 1, j), longestCommonSubsequence(word1, word2, i, j + 1));
    }

    // With Dynamic Programming + iteration (with longest common subsequence)
    int longestCommonSubsequenceWithDynamicProgramming(string &word1, string &word2)
    {
        int n = word1.size();
        int m = word2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return n + m - (2 * dp[0][0]);
    }

    // Iteration + Dynamic Programming (without longest common subsequence)
    int solveWithDynamicProgramming(string &word1, string &word2)
    {
        int n = word1.size();
        int m = word2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        // int n = word1.size();
        // int m = word2.size();
        // dp = vector<vector<int>>(n, vector<int>(m, -1));
        // return n + m - (2 * longestCommonSubsequence(word1, word2, 0, 0));

        // return longestCommonSubsequenceWithDynamicProgramming(word1, word2);

        return solveWithDynamicProgramming(word1, word2);
    }
};

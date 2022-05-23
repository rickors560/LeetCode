#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<vector<int>>> dp;
    int recursive(vector<string> &strs, int m, int n, int index)
    {
        if (index == strs.size() || m + n == 0)
            return 0;

        if (dp[m][n][index])
            return dp[m][n][index];

        int *c = count(strs[index]);

        int consider = 0;

        if (m >= c[0] && n >= c[1])
            consider = 1 + recursive(strs, m - c[0], n - c[1], index + 1);

        int skip = recursive(strs, m, n, index + 1);
        return dp[m][n][index] = max(consider, skip);
    }

    int *count(string &s)
    {
        int result[2] = {};
        for (char c : s)
            result[c - '0']++;
        return result;
    }

    int iterative(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (string s : strs)
        {
            int *c = count(s);

            for (int zero = m; zero >= c[0]; zero--)
            {
                for (int one = n; one >= c[1]; one--)
                {
                    dp[zero][one] = max(1 + dp[zero - c[0]][one - c[1]], dp[zero][one]);
                }
            }
        }

        return dp[m][n];
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size())));
        // return recursive(strs, m, n, 0);
        return iterative(strs, m, n);
    }
};
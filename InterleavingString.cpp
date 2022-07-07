#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp = vector<vector<int>>(101, vector<int>(101, -1));

    bool dfs(string &s1, string &s2, string &s3, int a, int b)
    {
        if (a + b == s3.size())
            return true;

        if (dp[a][b] != -1)
            return dp[a][b] ? true : false;

        bool x = false, y = false;
        if (a < s1.size() && s1[a] == s3[a + b])
            x = dfs(s1, s2, s3, a + 1, b);

        if (b < s2.size() && s2[b] == s3[a + b])
            y = dfs(s1, s2, s3, a, b + 1);

        return dp[a][b] = x || y;
    }

    bool bottomUp(string &s1, string &s2, string &s3)
    {
        int n = s1.size();
        int m = s2.size();

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                else if (i == 0)
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]);
                else
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]);
            }
        }

        return dp[n][m];
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size())
            return false;

        return bottomUp(s1, s2, s3);
        // return dfs(s1, s2, s3, 0, 0);
    }
};
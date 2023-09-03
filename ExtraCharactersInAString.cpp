#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> dp;
    int solve(string &s, vector<string> &dictionary, int index)
    {
        if (index == s.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        dp[index] = 1 + solve(s, dictionary, index + 1);
        for (const auto word : dictionary)
        {
            if (s.compare(index, word.size(), word) == 0)
            {
                dp[index] = min(dp[index], solve(s, dictionary, index + word.size()));
            }
        }

        return dp[index];
    }

public:
    Solution() : dp(51, -1)
    {
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        return solve(s, dictionary, 0);
    }
};
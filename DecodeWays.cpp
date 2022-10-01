#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dp;

    int decode(int position, string &s)
    {
        int n = s.size();
        if (position == n)
            return 1;

        if (dp[position] != 0)
            return dp[position];

        if (s[position] == '0')
            return 0;

        int result = decode(position + 1, s);

        if (position + 1 < n && (s[position] == '1' || (s[position] == '2' && s[position + 1] < '7')))
            result += decode(position + 2, s);

        return dp[position] = result;
    }

    int decode2(string &s)
    {
        int n = s.size();
        dp = vector<int>(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 0)
                dp[i] = 0;
            else
            {
                dp[i] += dp[i + 1];
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }

public:
    int numDecodings(string s)
    {
        // dp = vector<int>(s.size(), 0);
        // return s.empty() ? 0 : decode(0, s);
        return s.empty() ? 0 : decode2(s);
    }
};
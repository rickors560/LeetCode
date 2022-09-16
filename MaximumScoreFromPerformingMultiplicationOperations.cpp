#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int op = m - 1; op >= 0; op--)
        {
            for (int left = n - 1; left >= 0; left--)
            {
                long l = multipliers[op] * nums[left] + dp[op + 1][left + 1];
                long r = multipliers[op] * nums[(n - 1) - (op - left)] + dp[op + 1][left];
                dp[op][left] = max(l, r);
            }
        }

        return dp[0][0];
    }
};
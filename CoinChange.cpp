#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Store the no. of minimum coins to reach that amount and
        // default value is INT_MAX as we dont know whether we can get that amount with any no. of coins
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                int remainingAmount = i - coin;

                // If remaining amount is negative or for remaining amount we dont know minimum no. of coins
                // Then we dont include coin.
                if (remainingAmount < 0 || dp[remainingAmount] == INT_MAX)
                    continue;

                // 1 + dp[remainingAmount] => 1 for coin itself and dp[remainingAmount] for the no. of coins for remaining amount
                dp[i] = min(dp[i], 1 + dp[remainingAmount]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
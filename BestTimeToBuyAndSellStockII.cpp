#include <bits/stdc++.h>
using namespace std;

// <=====================================> Using Tabulation(Iteration) + Space Optimization for DP <=====================================>

class Solution
{

public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> cur(2, 0);
        vector<int> ahead(2, 0);

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                if (canBuy == 1)
                {
                    // Whether he buys or not for that current day
                    cur[canBuy] = max(-prices[index] + ahead[0], 0 + ahead[1]);
                }
                else
                {
                    // Whether he sells or not for that current day
                    cur[canBuy] = max(prices[index] + ahead[1], 0 + ahead[0]);
                }
            }
            ahead = cur;
        }

        return cur[1];
    }
};

// <=====================================> Using Tabulation(Iteration) <=====================================>

class Solution2
{

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        dp[prices.size()][0] = 0; // Base Case
        dp[prices.size()][1] = 0; // Base Case

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                if (canBuy == 1)
                {
                    // Whether he buys or not for that current day
                    dp[index][canBuy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
                }
                else
                {
                    // Whether he sells or not for that current day
                    dp[index][canBuy] = max(prices[index] + dp[index + 1][1], 0 + dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};

// <=====================================> Using Memoization(Recursion) <=====================================>

class Solution1
{
    // CanBuy => 1 == true ; 0 == false
    int solve(int index, int canBuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];

        int profit;
        if (canBuy == 1)
        {
            // Whether he buys or not for that current day
            profit = max(-prices[index] + solve(index + 1, 0, prices, dp), 0 + solve(index + 1, 1, prices, dp));
        }
        else
        {
            // Whether he sells or not for that current day
            profit = max(prices[index] + solve(index + 1, 1, prices, dp), 0 + solve(index + 1, 0, prices, dp));
        }

        return dp[index][canBuy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
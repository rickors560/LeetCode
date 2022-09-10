#include <bits/stdc++.h>
using namespace std;

// <=====================================> Using Tabulation(Iteration) + Space Optimization for DP <=====================================>

class Solution
{

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> cur(2, vector<int>(3, 0));
        vector<vector<int>> ahead(2, vector<int>(3, 0));

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                // As availableTransactions == 0 is one of the base case and it always 0 so we can skip that
                for (int availableTransactions = 1; availableTransactions <= 2; availableTransactions++)
                {
                    if (canBuy == 1)
                    {
                        // Whether he buys or not for that current day
                        cur[canBuy][availableTransactions] = max(-prices[index] + ahead[0][availableTransactions], 0 + ahead[1][availableTransactions]);
                    }
                    else
                    {
                        // Whether he sells or not for that current day
                        cur[canBuy][availableTransactions] = max(prices[index] + ahead[1][availableTransactions - 1], 0 + ahead[0][availableTransactions]);
                    }
                }
            }
            ahead = cur;
        }

        return cur[1][2];
    }
};

// <=====================================> Using Tabulation(Iteration) <=====================================>

class Solution2
{

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                // As availableTransactions == 0 is one of the base case and it always 0 so we can skip that
                for (int availableTransactions = 1; availableTransactions <= 2; availableTransactions++)
                {
                    if (canBuy == 1)
                    {
                        // Whether he buys or not for that current day
                        dp[index][canBuy][availableTransactions] = max(-prices[index] + dp[index + 1][0][availableTransactions], 0 + dp[index + 1][1][availableTransactions]);
                    }
                    else
                    {
                        // Whether he sells or not for that current day
                        dp[index][canBuy][availableTransactions] = max(prices[index] + dp[index + 1][1][availableTransactions - 1], 0 + dp[index + 1][0][availableTransactions]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

// <=====================================> Using Memoization(Recursion) <=====================================>

class Solution1
{
    // CanBuy => 1 == true ; 0 == false
    int solve(int index, int canBuy, vector<int> &prices, vector<vector<vector<int>>> &dp, int availableTransactions)
    {
        if (availableTransactions == 0)
            return 0;

        if (index == prices.size())
            return 0;

        if (dp[index][canBuy][availableTransactions] != -1)
            return dp[index][canBuy][availableTransactions];

        int profit;
        if (canBuy == 1)
        {
            // Whether he buys or not for that current day
            profit = max(-prices[index] + solve(index + 1, 0, prices, dp, availableTransactions), 0 + solve(index + 1, 1, prices, dp, availableTransactions));
        }
        else
        {
            // Whether he sells or not for that current day
            profit = max(prices[index] + solve(index + 1, 1, prices, dp, availableTransactions - 1), 0 + solve(index + 1, 0, prices, dp, availableTransactions));
        }

        return dp[index][canBuy][availableTransactions] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, prices, dp, 2);
    }
};
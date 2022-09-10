#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minimumBuyPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int currentCost = prices[i] - minimumBuyPrice;
            profit = max(profit, currentCost);
            minimumBuyPrice = min(minimumBuyPrice, prices[i]);
        }

        return profit;
    }
};

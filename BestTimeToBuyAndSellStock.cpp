#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int priceToBuy = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int priceToSell = prices[i];
            int currentCost = priceToSell - priceToBuy;
            profit = max(profit, currentCost);
            priceToBuy = min(priceToBuy, prices[i]);
        }

        return profit;
    }
};
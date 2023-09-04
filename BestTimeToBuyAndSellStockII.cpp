#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        int priceToBuy = prices[0];
        int index = 0;

        while (index < prices.size())
        {
            int profit = 0;

            while (index + 1 < prices.size() && prices[index] <= prices[index + 1])
                index++;

            profit = prices[index] - priceToBuy;

            if (index + 1 < prices.size())
                priceToBuy = prices[index + 1];

            index++;
            result += profit;
        }

        return result;
    }
};

int main()
{
    vector<int> x = {7, 1, 5, 3, 6, 4};
    Solution s;
    s.maxProfit(x);
}
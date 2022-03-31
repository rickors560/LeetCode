#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    static bool comparator(vector<int> &x, vector<int> &y)
    {
        // Comparing if which is more profitale to go city A either x or y
        // x[0] - x[1] => the extra amount needed to go city A than city B // the lesser the more profitable to go city A
        return (x[0] - x[1]) < (y[0] - y[1]);
    }

public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        // Sorting costs in such a way people which are more profitable to go city A
        sort(costs.begin(), costs.end(), comparator);

        int result = 0;

        // Sending 1st half to city A
        for (int i = 0; i < costs.size() / 2; i++)
        {
            result += costs[i][0];
        }

        // Sending 2nd half to city B
        for (int i = costs.size() / 2; i < costs.size(); i++)
        {
            result += costs[i][1];
        }

        return result;
    }
};
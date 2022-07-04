#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using 1 Array
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        int result = 0;

        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
                candies[i] = candies[i - 1] + 1;
        }

        result = candies[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i])
                candies[i] = max(candies[i], candies[i + 1] + 1);

            result += candies[i];
        }

        return result;
    }

    // Using 2 Arrays
    int candy1(vector<int> &ratings)
    {
        int n = ratings.size();

        int result = 0;

        vector<int> left2Right(n, 1);
        vector<int> right2Left(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
                left2Right[i] = left2Right[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i])
                right2Left[i] = right2Left[i + 1] + 1;
        }

        for (int i = 0; i < n; i++)
            // max in order to satisfy both neighbour's relationship
            result += max(left2Right[i], right2Left[i]);

        return result;
    }
};
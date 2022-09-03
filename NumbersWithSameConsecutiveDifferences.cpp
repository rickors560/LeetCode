#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int level, int k, int num, vector<int> &result)
    {
        if (level == 0)
        {
            result.push_back(num);
            return;
        }

        vector<int> nextDigits;

        int tailDigit = num % 10;

        nextDigits.push_back(tailDigit + k);
        if (k != 0)
            nextDigits.push_back(tailDigit - k);

        for (auto nextDigit : nextDigits)
        {
            if (nextDigit >= 0 && nextDigit < 10)
            {
                int next = num * 10 + nextDigit;
                dfs(level - 1, k, next, result);
            }
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        if (n == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<int> result;
        for (int i = 1; i < 10; i++)
            dfs(n - 1, k, i, result);

        return result;
    }
};
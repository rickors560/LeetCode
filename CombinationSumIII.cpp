#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void backTrack(int k, int n, vector<vector<int>> &result, vector<int> res, int x, int sum)
    {
        if (sum == n and res.size() == k)
        {
            result.push_back(res);
            return;
        }

        for (int i = x + 1; i < 10; i++)
        {
            res.push_back(i);
            backTrack(k, n, result, res, i, sum + i);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> sol;
        backTrack(k, n, result, sol, 0, 0);
        return result;
    }
};
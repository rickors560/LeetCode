#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void backTrack(vector<vector<int>> &result, vector<int> &nums, unordered_map<int, int> count, vector<int> sol)
    {
        if (sol.size() == nums.size())
        {
            result.push_back(sol);
            return;
        }

        for (auto entrySet : count)
        {
            auto key = entrySet.first;

            if (count[key] == 0)
                continue;

            count[key] -= 1;
            sol.push_back(key);

            backTrack(result, nums, count, sol);

            count[key] += 1;
            sol.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> sol;

        unordered_map<int, int> count;

        for (auto num : nums)
        {
            count[num] += 1;
        }

        backTrack(result, nums, count, sol);
        return result;
    }
};
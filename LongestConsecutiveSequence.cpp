#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> lookUp(nums.begin(), nums.end());

        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (lookUp.find(nums[i] - 1) != lookUp.end())
                continue;

            int count = 0;
            int current = nums[i];

            while (lookUp.find(current) != lookUp.end())
            {
                count++;
                current++;
            }

            result = max(result, count);
        }

        return result;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> runningSum1(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }

    vector<int> runningSum(vector<int> &nums)
    {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = 0;

        for (int i = 0; i < n / 2; i++)
            // result += ( median - left ) + (right - median) == (right - left)
            result += nums[n - 1 - i] - nums[i];

        return result;
    }
};
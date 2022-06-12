#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int target = -x;

        for (auto num : nums)
            target += num;

        if (target == 0)
            return nums.size();

        if (target < 0)
            return -1;

        int sum = 0;
        int left = 0;
        int right = 0;

        int res = -1;

        while (right < nums.size())
        {
            sum += nums[right];

            while (sum > target)
            {
                sum -= nums[left++];
            }
            if (sum == target)
                res = max(res, right - left + 1);

            right++;
        }

        return res == -1 ? -1 : nums.size() - res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void twoSum(vector<int> &nums, long target, int a, int b, vector<vector<int>> &result)
    {
        int l = b + 1;
        int r = nums.size() - 1;

        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                result.push_back({nums[a], nums[b], nums[l], nums[r]});
                l++;
                r--;

                while (l < r && nums[l] == nums[l - 1])
                    l++;
            }
            else if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                twoSum(nums, (long)target - nums[i] - nums[j], i, j, result);

                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return result;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();

        // Sort the list so that we remove duplicates and apply two pointer (move left if sum too big or move right if sum is too small)
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
        {
            // To skip duplicate values for i index
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    // Move left pointer till the new distinct value
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                }
                else if (sum > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        return result;
    }
};
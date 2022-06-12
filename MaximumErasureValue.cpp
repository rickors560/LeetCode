#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using hash map
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int sum = 0;
        int result = 0;

        unordered_map<int, int> seen;

        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (seen.find(nums[r]) != seen.end())
            {
                int i = seen[nums[r]];

                while (l <= i)
                {
                    seen.erase(nums[l]);
                    sum -= nums[l++];
                }
            }

            seen[nums[r]] = r;
            sum += nums[r];
            result = max(result, sum);
        }

        return result;
    }

    // Using hash set
    int maximumUniqueSubarray1(vector<int> &nums)
    {
        int sum = 0;
        int result = 0;

        unordered_set<int> seen;

        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            while (seen.find(nums[r]) != seen.end())
            {
                seen.erase(nums[l]);
                sum -= nums[l++];
            }

            seen.insert(nums[r]);
            sum += nums[r];
            result = max(result, sum);
        }

        return result;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = target >= 0 ? INT_MAX : INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int t = nums[i] + nums[l] + nums[r];

                if (t > target)
                    r--;
                else
                    l++;

                if (abs(target - t) < abs(target - result))
                    result = t;
            }
        }
        return result;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = nums[i] * nums[i];

        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        vector<int> result(nums.size());

        while (i <= j)
        {
            if (nums[i] >= nums[j])
            {
                result[k] = nums[i];
                i++;
            }
            else
            {
                result[k] = nums[j];
                j--;
            }
            k--;
        }

        return result;
    }
};
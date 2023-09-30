#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool monotoneIncreasing = true;
        bool monotoneDecreasing = true;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                monotoneIncreasing = false;
            }

            if (nums[i] < nums[i + 1])
            {
                monotoneDecreasing = false;
            }

            if (!monotoneIncreasing && !monotoneDecreasing)
                break;
        }

        return monotoneIncreasing || monotoneDecreasing;
    }
};
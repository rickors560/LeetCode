#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();

        int down = 1;
        int up = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1; // Uphill case
            else if (nums[i] < nums[i - 1])
                down = up + 1; // Downhill case

            // In case of consecutive down/up cases or equal case we use same up and down value as they belong to same group
        }

        return max(down, up);
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int minInSub = INT_MAX;
        int maxInSub = INT_MIN;

        bool isFound = false;

        // Find minimum in unsorted subarray
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
                isFound = true;

            if (isFound)
                minInSub = min(minInSub, nums[i]);
        }

        isFound = false;

        // Find maximum in unsorted subarray
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
                isFound = true;

            if (isFound)
                maxInSub = max(maxInSub, nums[i]);
        }

        int l, r;

        // Find correct position of minimum
        for (l = 0; l < n; l++)
        {
            if (minInSub < nums[l])
                break;
        }

        // Find correct position of maximum
        for (r = n - 1; r >= 0; r--)
        {
            if (maxInSub > nums[r])
                break;
        }

        return r - l > 0 ? r - l + 1 : 0;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int longestPrefixIndex = -1; // As per dictionary order

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                longestPrefixIndex = i;
                break;
            }
        }

        if (longestPrefixIndex == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= longestPrefixIndex + 1; i--)
        {
            if (nums[i] > nums[longestPrefixIndex])
            {
                swap(nums[i], nums[longestPrefixIndex]);
                break;
            }
        }

        // Reversing the 2nd Half as its already in decreasing order and
        // it order to maintain dictionary order it need to be in ascending order.
        reverse(nums.begin() + longestPrefixIndex + 1, nums.end());
    }
};
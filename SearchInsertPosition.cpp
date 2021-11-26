#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        int mid = (end + start) / 2;

        if (start <= end)
        {
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
            {
                return binarySearch(nums, target, start, mid - 1);
            }

            else
            {
                return binarySearch(nums, target, mid + 1, end);
            }
        }
        return start;
    }
};
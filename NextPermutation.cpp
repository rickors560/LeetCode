#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    void reverse(vector<int> &nums, int i)
    {
        int j = nums.size() - 1;
        while (i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = nums.size() - 1;

            while (nums[i] >= nums[j])
            {
                j--;
            }
            swap(nums, i, j);
        }

        reverse(nums, i + 1);
    }
};
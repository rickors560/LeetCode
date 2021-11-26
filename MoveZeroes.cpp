#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;
        int j = 0;

        while (i < n && j < n)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
            
            i++;
        }
    }
};
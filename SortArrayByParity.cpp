#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> ans;

        int n = nums.size();

        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (nums[i] % 2 != 0 && nums[j] % 2 == 0)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }

            if (nums[i] % 2 == 0)
                i++;

            if (nums[j] % 2 != 0)
                j--;
        }

        return ans;
    }

    vector<int> sortArrayByParity1(vector<int> &nums)
    {
        vector<int> ans;

        int n = nums.size();

        int i = 0;
        int j = 0;

        while (i < n || j < n)
        {
            if (i < n)
            {
                while (i < n)
                {
                    if (nums[i] % 2 == 0)
                        ans.push_back(nums[i]);
                    i++;
                }
            }

            if (j < n)
            {
                while (j < n)
                {
                    if (nums[j] % 2 != 0)
                        ans.push_back(nums[j]);
                    j++;
                }
            }

            i++;
            j++;
        }

        return ans;
    }
};
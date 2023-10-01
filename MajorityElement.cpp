#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Using Moore's Voting Algo
        int n = nums.size();
        int el;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                el = nums[i];
                count++;
            }
            else if (nums[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return el;
    }

    int majorityElement2(vector<int> &nums)
    {
        // Using sorting
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Using Moore Voting Algorithm
        // Result will contain at max 2 elements for majority of > n/3
        vector<int> result;
        int threshold = nums.size() / 3;

        int el1, el2;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count1 == 0 && nums[i] != el2)
            {
                el1 = nums[i];
                count1++;
            }
            else if (count2 == 0 && nums[i] != el1)
            {
                el2 = nums[i];
                count2++;
            }
            else if (nums[i] == el1)
            {
                count1++;
            }
            else if (nums[i] == el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }

        if (cnt1 > threshold)
            result.push_back(el1);

        if (cnt2 > threshold)
            result.push_back(el2);

        return result;
    }

    // Using Hash Map
    vector<int> majorityElement2(vector<int> &nums)
    {
        int threshold = nums.size() / 3;
        unordered_map<int, int> mp;
        vector<int> result;

        for (auto num : nums)
        {
            mp[num]++;
        }

        for (auto el : mp)
        {
            if (el.second > threshold)
            {
                result.push_back(el.first);
            }
        }

        return result;
    }
};
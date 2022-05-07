#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pair<int, int>> st;

        int currentMin = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            while (!st.empty() and nums[i] >= st.top().first)
            {
                st.pop();
            }

            if (!st.empty() and nums[i] > st.top().second)
            {
                return true;
            }

            st.push({nums[i], currentMin});

            currentMin = min(currentMin, nums[i]);
        }

        return false;
    }
};
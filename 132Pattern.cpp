#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> st;
        int secondMax = INT_MIN; // Act as Kth element in the pattern

        for (int x = nums.size() - 1; x >= 0; x--)
        {
            if (nums[x] < secondMax) // Act as Ith element in the pattern
                return true;

            while (!st.empty() && nums[x] > st.top())
            {
                secondMax = max(secondMax, st.top());
                st.pop();
            }

            // Act as Jth element in the pattern
            st.push(nums[x]);
        }

        return false;
    }
};
// i < j < k
// nums[i] < nums[k], nums[k] < nums[j]
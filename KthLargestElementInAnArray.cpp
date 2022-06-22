#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using priority queue (max heap)
    int findKthLargest1(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());

        while (k-- > 1)
            pq.pop();

        return pq.top();
    }

    // Using nth_element (Partial Sorting)
    int findKthLargest2(vector<int> &nums, int k)
    {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }

    // Using partial_sort (Partial Sorting)
    int findKthLargest3(vector<int> &nums, int k)
    {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
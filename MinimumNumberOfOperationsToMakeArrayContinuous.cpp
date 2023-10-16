#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int result = n;
        unordered_set<int> set;

        for (int x : nums)
        {
            set.insert(x);
        }

        vector<int> unique(set.begin(), set.end());
        sort(unique.begin(), unique.end());

        int right = 0;
        int range = unique.size();

        for (int left = 0; left < range; left++)
        {

            // nums[left] -> nums[left] + n - 1
            while (right < range && unique[right] < unique[left] + n)
            {
                right++;
            }
            int window = right - left;
            result = min(result, n - window);
        }

        return result;
    }
};
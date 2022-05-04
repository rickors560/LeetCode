#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> lookUp;

        int count = 0;

        for (auto n : nums)
        {
            int t = k - n;
            if (lookUp[t] != 0)
            {
                count++;
                lookUp[t]--;
            }
            else
            {
                lookUp[n]++;
            }
        }

        return count;
    }
};
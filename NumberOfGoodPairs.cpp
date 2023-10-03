#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> count;
        int result = 0;

        for (int num : nums)
        {
            result += count[num]++;
        }

        return result;
    }
};
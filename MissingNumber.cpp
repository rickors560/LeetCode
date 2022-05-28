#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0, i = 0; // a^b^b = a ->using xor property

        for (i = 0; i < nums.size(); i++)
        {
            res = res ^ i ^ nums[i];
        }
        return res ^ nums.size();
    }
};